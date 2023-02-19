#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16;

#define LED_PORT P2

//
void Delay_10us(u16 ten_us)
{
	while(ten_us--);
} 
void main()
{
	u8 i = 0;
	while(1)
	{
		for(i=0;i<8;i++)
		{
				LED_PORT = ~(0x01<<i);
				Delay_10us(50000);
		}
	}
}