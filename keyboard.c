#include "isr.h"
#include "monitor.h"
#include "keyboard.h"

/// Keyboard ScanCodes

static void keyboard_callback(registers_t regs)
{
    u8int status = inb(0x64);
    monitor_write_dec(status);
    monitor_write("keyboard Button: ");
    u8int scancode = inb(0x60);
    monitor_write_dec(scancode);
    monitor_write("\n");
}

void init_keyboard()
{
    // Firstly, register our timer callback.
    register_interrupt_handler(IRQ1, &keyboard_callback);
    
    /*
    u8int status = inb(0x64);
	u8int scancode = inb(0x60);
    monitor_write_dec(status);
    monitor_put('\n');
    monitor_write_dec(scancode);
    monitor_put('\n');
    */

}