#include<reg51.h>
#include<delay.h>
#include<lcd.h>
sbit s1=P3^0;
sbit s2=P3^1;
sbit s3=P3^2;
void main()
{
    int M=65,g,T,B;
	P0=0;
	lcd_init();
                  lcd_cmd(0x80);
                  lcd_puts(" Sending Data!!");  
				  secdelay(1);
				  
    SCON=0x50;
	TMOD=0x20;

	g=11.0592/12;
	T=g/32;
	
	B=T/9600;

	TL1=TH1=0xfd;
	TR1=1;
	
   
  lcd_cmd(0x01);
				  ms_delay(500);
	while(1)
{
    			  lcd_cmd(0x80);
                  lcd_puts("DATA....");
				  while(s3!=0)
				  {
				  if(s1==0)
				  {
				  M++;
				  while(s1==0);
				  }  
                  if(s2==0)
				  {
				  M--;
				  while(s2==0);
				  }
				  lcd_cmd(0xc0);
				  lcd_dat(M);
				  }
				  SBUF=M;
				  while(TI!=1);
				  lcd_cmd(0x80);
                  lcd_puts("sent....");
				  TI=0;
				  while(s3==0);
}
}