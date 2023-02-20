#include "reg52.h"

sbit BEEP = P2^5;
sbit LED0 = P2^0;

void Delay_10us(int ten_us)
{
	while(ten_us--);
}
void main()
{
	while(1)
	{
		int i = 2000;
		while(i--)
		{		
			BEEP = !BEEP;
			Delay_10us(10);
		}
		Delay_10us(200);
		BEEP = 0;
		i = 200;
		while(i--)
		{
			BEEP = !BEEP;
			Delay_10us(100);
		}
		Delay_10us(200);
		BEEP = 0;
		LED0=!LED0;
	}
}