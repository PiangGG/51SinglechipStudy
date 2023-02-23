#include "reg52.h"
#include "intrins.h"

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
	LED_PORT = ~0x01;
	while(1)
	{
		for(i=0;i<7;i++)
		{
				LED_PORT = _crol_(LED_PORT,1);
				Delay_10us(50000);
		}
		
		for(i=0;i<7;i++)
		{
				LED_PORT = _cror_(LED_PORT,1);
				Delay_10us(50000);
		}
	}
}