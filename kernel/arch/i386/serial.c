#include <kernel/serial.h>
#include <kernel/io.h>
void string_serial_write(char a[]);
void init_serial();
void init_serial();
char read_serial();
int is_transmit_empty();
void write_serial(char a);
void init_serial()
{
    outb(0x3f8+1,0x00);//disable interrupt
    outb(0x3f8+0,0x00);//cls data ref
    outb(0x3f8+3,0x80);//set DLAB to 1(0x80)
    outb(0x3f8+0,0x03);//3 is the divisor
    outb(0x3f8+1,0x00);//high bit
    outb(0x3f8+3,0x03);//8-bit
    outb(0x3f8+2,0xC7);//FIFO
    outb(0x3f8+4,0x0B);//line status
}
void string_serial_write(char a[])
{
    int i=0;
    while(a[i]!='\0')
    {
        write_serial(a[i]);
        i++;
    }
}
int serial_received() {
   return inb(0x3f8 + 5) & 1;
}
 
char read_serial() {
   while (serial_received() == 0);
 
   return inb(0x3f8);
}
int is_transmit_empty() {
   return inb(0x3f8 + 5) & 0x20;
}
 
void write_serial(char a) {
   while (is_transmit_empty() == 0);
 
   outb(0x3f8,a);
}
