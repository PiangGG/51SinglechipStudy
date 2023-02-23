#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16;

#define SMG_A_DP_PORT P0^1;
sbit BEEP = P2^5;

u8 gsmg_code[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
									0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71}; //
//
void Delay_10us(u16 ten_us)
{
	while(ten_us--);
} 

void main()
{
	while(1)
	{
		int i = 0;
		int n1;
		for(i=9;i>=0;i--)
		{
			P0 = gsmg_code[i];
			n1 = 2000;
			while(n1--)
			{		
				BEEP = !BEEP;
				Delay_10us(10);
			}
			Delay_10us(50000);
		}
		P0 = 0x00;
		
		while(1)
		{
			n1 = 1000;
			while(n1--)
			{		
				BEEP = !BEEP;
				Delay_10us(5);
			}
			Delay_10us(20000);
		}
	}
}