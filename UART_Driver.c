#include <lpc21xx.h>
#include "header.h"
#define THRE ((U0LSR>>5)&1)
#define RDR ((U0LSR)&1)

// UART0 INITIALISATION //
void uart0_init(unsigned int baud)
{
	int a[]={15,60,30,0,15};
	unsigned int pclk=a[VPBDIV]*1000000; // set pclk
	unsigned int res=0;
	res=pclk/(16*baud);
	PINSEL0|=0x5; // set p0.0=tx and p0.1=rx
	U0LCR=0x83; // unlock baudrate settings
	U0DLL=res&0xFF; //set value for baud rate (LSB)
	U0DLM=(res>>8)&0xFF; // set value for baud rate (MSB)
	U0LCR=0x03; // lock baudrate settings
}

// UART0 TRANSMIT DATA //
void uart0_tx (unsigned char data)
{
	U0THR=data; // tranfer data to U0THR
	while(THRE==0); // wait till data transmit and U0THR is empty.
}

// UART0 STRING TRANSMIT //
void uart0_tx_string (s8*ptr)
{
	while (*ptr)
		{
			uart0_tx(*ptr);
			ptr++;
		}
}

//UART0 RECEIVE DATA //
u8 uart0_rx (void)
{
	while (RDR==0);
	return U0RBR;
}
