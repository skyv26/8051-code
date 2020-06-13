#include<reg51.h>
#include<delay.h>
#include<p2lcd.h>
sbit s3=P3^2;
void main()
{
    int M,T,B;
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
				  lcd_cmd(0xc0);
				  M=SBUF;
                  lcd_dat(M);
		 


}
}