#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit LED1 = P2^0;
sbit LED2 = P2^1;
sbit LED3 = P2^2;
sbit LED4 = P2^3;
sbit LED5 = P2^4;
sbit LED6 = P2^5;
sbit LED7 = P2^6;
sbit LED8 = P2^7;

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
		LED8 = 1;
		Delay_10us(5000);
		
		LED2 = 0;
		LED1 = 1;
		Delay_10us(5000);
		
		LED3 = 0;
		LED2 = 1;
		Delay_10us(5000);
		
		LED4 = 0;
		LED3 = 1;
		Delay_10us(5000);
		
		LED5 = 0;
		LED4 = 1;
		Delay_10us(5000);
		
		LED6 = 0;
		LED5 = 1;
		Delay_10us(5000);
		
		LED7 = 0;
		LED6 = 1;
		Delay_10us(5000);
		
		LED8 = 0;
		LED7 = 1;
		Delay_10us(5000);
	}
}