#include <stdio.h>
#include <kernel/io.h>
#include <kernel/tty.h>
#include <kernel/serial.h>
#define PORT 0x3f8   /* COM1 */
int is_transmit_empty();
void init_serial();
void write_serial(char a);
void kernel_main(void);
void kernel_main(void){
	terminal_initialize();
    int n=45;
	printk("Hello, kernel World!\nI am in kernel World\tGiving 1 tab worth of space\nThis line should not be printed or should be incompletely printed\rInstead this line should be printed\nControl should jump after this\vControl has jumped.\n now printing BACKSLASH (\\)\n Now printing SINGLE QUOTES(\')\n Now printing DOUBLE QUOTES(\")\n Now printing question mark(\?) What if i try to print an integer? Now printing 45:%d",&n);
	//CALLING WRITE init_serial
    init_serial();
    string_serial_write("HEll SERIAL!  going newline :\n NEW LINE=NEW LIFE\0");
    
}

 //FOR QEMU TEST
