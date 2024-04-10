#include <lpc21xx.h>
unsigned char dummy;

void UART0_Handler(void) __irq
{
	int temp=U0IIR;
	if (temp&4)
	{
		dummy=U0RBR;
		U0THR=dummy;
	}
	VICVectAddr=0;
}

void config_vic (void)
{
	//VICIntSelect=(1<<6);
	VICIntSelect=0;
	VICVectCntl0=6|(1<<5);
	VICVectAddr0=(int)UART0_Handler;
	VICIntEnable|=(1<<6);
}

void en_uart0_intr (void)
{
	U0IER=3;
}
