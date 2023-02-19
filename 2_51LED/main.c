#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit LED1 = P2^0;

//
void Delay_10us(u16 ten_us)
{
	while(ten_us--);
} 
void main()
{
	
	
	while(1)
	{
		LED1 = 0;
		Delay_10us(50000);
		LED1 = 1;
		Delay_10us(50000);
	}
}