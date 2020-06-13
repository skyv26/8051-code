#include<reg51.h>
#include<delay.h>
#include<lcd.h>
#define motor P0
#define adc P2
sbit SC=P3^3;
sbit bulb=P0^1;
#define off 0
#define on 1
void clk(unsigned char a)
{
unsigned char c;
for(c=0;c<a;c++)
{
motor=0X04;
ms_delay(30);
motor=0X08;
ms_delay(30);
motor=0X10;
ms_delay(30);
motor=0X20;
ms_delay(30);
}
}
void aclk(unsigned char b)
{
unsigned char d;
for(d=0;d<b;d++)
{
motor=0X20;
ms_delay(30);
motor=0X10;
ms_delay(30);
motor=0X08;
ms_delay(30);
motor=0X04;
ms_delay(30);
}
}
unsigned char ADC()
{
SC=0;
ms_delay(10);
SC=1;
ms_delay(20);
SC=0;
ms_delay(30);
return(adc);
}
void main()
{
	unsigned char Q;
    int A,M,T,B,f,S=0xc0;
	P0=0;
	lcd_init();
	lcd_cmd(0x01);                  
				  
	SCON=0x50;
	TMOD=0x20;

	M=11.0592/12;
	T=M/32;
	
	B=T/9600;

	TL1=TH1=0xfd;
	TR1=1;
	
  
  lcd_cmd(0x01);
				  lcd_cmd(0x80);
                  lcd_puts("  Recieving...  ");
				  
	while(1)
{			     
				  while(RI!=1);
				  RI=0;
				  M=SBUF;
				  lcd_cmd(S);
			      lcd_dat(M);
                  S++;
				  	if(S>0xcf)
						S=0xc0;
		          else if(M==8)
				  {
				  lcd_cmd(0xc0);
                  lcd_puts("                ");
				  S=0xc0;
				  f=0;
				  }
				  else if(M=='`')
				  {
				   S--;
				   	lcd_cmd(S);
					lcd_dat(' ');
						if(S<0xc0)
						S=0xc0;
			      }
		          else if(M==49)
				  {
				  while(RI==0)
				  {
				  clk(1);
				  }
		          }
				  else if(M==50)
				  {
				  while(RI==0)
				  {
				  motor=off;
				  aclk(1);
				  }
				  }
				  else if(M==51)
				  {
				   bulb=on;
				  }
				  else if(M==52)
				  {
				                   lcd_init();  
                                   lcd_cmd(0x01);
                				   lcd_cmd(0x80);
                 				   lcd_puts("Light Intensity!");
	     					       lcd_cmd(0xc3);
                                   lcd_puts("%");
                   while(RI==0  )
                  {
                             lcd_cmd(0xc0);
				             Q=ADC();
				             Q=Q/2.55;
				             lcd_print(Q);
				             ms_delay(200);
				   
                  }
				  }
				  else
	              {
				   adc=off;
				   motor=off;
				  }	    
				  }

				  			  
}				   