#include<reg51.h>
#include<delay.h>
#include<lcd.h>
#define adc P2
sbit SC=P3^3;
sbit s1=P3^0;
sbit s2=P3^1;
sbit s3=P3^2;

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
//bit f;
P0=0;
lcd_init();  
                  lcd_cmd(0x01);
                  lcd_cmd(0x80);
                  lcd_puts("Light Intensity!");
		  lcd_cmd(0xc3);
                  lcd_puts("%");
while(1)
{
                  lcd_cmd(0xc0);
				  Q=ADC();
				  Q=Q/2.55;
				  lcd_print(Q);
				  ms_delay(200);
}
}