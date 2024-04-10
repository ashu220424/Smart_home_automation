#include<lpc21xx.h>
#include "header.h"
#define LED1 (1<<17)
#define LED2 (1<<18)
#define LED3 (1<<19)
extern unsigned char dummy;
int main()
{
	uart0_init(9600);
	config_vic();
	en_uart0_intr();
	IODIR0=LED1|LED2|LED3;
	uart0_tx_string("LED MENU\r\n");
	uart0_tx_string("a)LED1 ON \r\nb)LED1 OFF \r\nc)LED2 ON \r\nd)LED2 OFF \r\ne)LED3 ON \r\nf)LED3 OFF \r\n");
	while (1)
	{
		while (dummy=='a')
		{
			IOSET0=LED1;
		}
		while (dummy=='b')
		{
			IOCLR0=LED1;

		}
		while (dummy=='c')
		{
			IOSET0=LED2;
		}
		while (dummy=='d')
		{
			IOCLR0=LED2;

		}
		while (dummy=='e')
		{
			IOSET0=LED3;
		}
		while (dummy=='f')
		{
			IOCLR0=LED3;

		}
	}
}
