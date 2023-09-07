#include <uefi.h>

/**
 * Classic Hello World example
 */
int main(int argc, char **argv)
{
    int a;
    int b;
    int c;
    (void)argc;
    (void)argv;
	a = 0x40b00000;
	b = 0x41300000;
	__asm__ volatile (
	    "fld %[b];"      
	    "fadd %[a];"      
	    "fstp %[c];"     
	    : [c] "=m" (c)
	    : [a] "m" (a), [b] "m" (b)
	);
    printf("Hello World! %X\n",c);
    sleep(2000000);
    return 0;
}
