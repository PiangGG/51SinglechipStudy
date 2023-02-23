#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16;

#define SMG_A_DP_PORT P0;

sbit LSA =P2^2;
sbit LSB =P2^3;
sbit LSC =P2^4;
sbit BEEP = P2^5;

u8 gsmg_code[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
									0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

void Delay_10us(u16 ten_us);
void Smg_Display(u8 c);
									
void Smg_Display(u8 c)
{
	u8 i= 0;
	
	switch(c)
	{
		case 0:
			for(i=0;i<8;i++)
			{
				switch(i)
				{
					case 0:
						LSC=1;
						LSB=1;
						LSA=1;
						P0 = gsmg_code[7];
						break;
					case 1:
						LSC=1;
						LSB=1;
						LSA=0;
						P0 = gsmg_code[0];
						break;
					case 2:
						LSC=1;
						LSB=0;
						LSA=1;
						P0 = gsmg_code[7];
						break;
					case 3:
						LSC=1;
						LSB=0;
						LSA=0;
						P0 = gsmg_code[2];
						break;
					case 4:
						LSC=0;
						LSB=1;
						LSA=1;
						P0 = gsmg_code[2];
						break;
					case 5:
						LSC=0;
						LSB=1;
						LSA=0;
						P0 = gsmg_code[3];
						break;
					case 6:
						LSC=0;
						LSB=0;
						LSA=1;
						P0 = gsmg_code[9];
						break;
					case 7:LSC=0;LSB=0;LSA=0;
						P0 = gsmg_code[7];
						break;
					default:
						break;
				}
				Delay_10us(100);
			}
			break;
		case 1:
			for(i=0;i<8;i++)
			{
				switch(i)
				{
					case 0:
						LSC=1;
						LSB=1;
						LSA=1;
						P0 = gsmg_code[6];
						break;
					case 1:
						LSC=1;
						LSB=1;
						LSA=0;
						P0 = gsmg_code[4];
						break;
					case 2:
						LSC=1;
						LSB=0;
						LSA=1;
						P0 = gsmg_code[5];
						break;
					case 3:
						LSC=1;
						LSB=0;
						LSA=0;
						P0 = gsmg_code[8];
						break;
					case 4:
						LSC=0;
						LSB=1;
						LSA=1;
						P0 = gsmg_code[3];
						break;
					case 5:
						LSC=0;
						LSB=1;
						LSA=0;
						P0 = gsmg_code[0];
						break;
					case 6:
						LSC=0;
						LSB=0;
						LSA=1;
						P0 = gsmg_code[7];
						break;
					case 7:LSC=0;LSB=0;LSA=0;
						P0 = gsmg_code[9];
						break;
					default:
						break;
				}
				Delay_10us(100);
			}
			break;
			case 2:
			for(i=0;i<8;i++)
			{
				switch(i)
				{
					case 0:
						LSC=1;
						LSB=1;
						LSA=1;
						P0 = gsmg_code[5];
						break;
					case 1:
						LSC=1;
						LSB=1;
						LSA=0;
						P0 = gsmg_code[2];
						break;
					case 2:
						LSC=1;
						LSB=0;
						LSA=1;
						P0 = gsmg_code[0];
						break;
					case 3:
						LSC=1;
						LSB=0;
						LSA=0;
						P0 = gsmg_code[1];
						break;
					case 4:
						LSC=0;
						LSB=1;
						LSA=1;
						P0 = gsmg_code[3];
						break;
					case 5:
						LSC=0;
						LSB=1;
						LSA=0;
						P0 = gsmg_code[1];
						break;
					case 6:
						LSC=0;
						LSB=0;
						LSA=1;
						P0 = gsmg_code[4];
						break;
					case 7:LSC=0;LSB=0;LSA=0;
						P0 = 0;
						break;
					default:
						break;
				}
				Delay_10us(100);
			}
			break;
	}
}
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
		int q1;
		LSC=1;
		LSB=1;
		LSA=1;
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
		q1 = 200;
		while(q1--)
		{
			
			n1 = 10;
			while(n1--)
			{		
				BEEP = !BEEP;
				Delay_10us(20);
			}
			Delay_10us(200);
		}
		
		q1= 100;
		while(q1--)
		{
			Smg_Display(2);
		}
	}
}