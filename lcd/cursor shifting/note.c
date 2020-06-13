#include<reg51.h>
#include<delay.h>
#define data P1
sbit s1=P3^0;
sbit s2=P3^1;
sbit s3=P3^2;
sbit RS=P3^5;
sbit RW=P3^6;
sbit EN=P3^7;
void lcd_cmd(unsigned char temp)
{
RS=0;
RW=0;
data=temp;
EN=1;
ms_delay(10);
EN=0;
}
void lcd_dat(unsigned char temp)
{
RS=1;
RW=0;
data=temp;
EN=1;
ms_delay(10);
EN=0;
}
void lcd_init()
{
lcd_cmd(0x38);
lcd_cmd(0x06);
lcd_cmd(0x0c);
lcd_cmd(0x01);
}
void lcd_puts(unsigned char *str)
{
while(*str!='\0')
	{
	lcd_dat(*str);
	str++;
	}
}
void main()
{
signed char i,s=0xc0;
//bit f;
P0=0;
P2=0xff;
lcd_init();
lcd_cmd(0x84);
lcd_puts("PASSWORD");
while(1)
{ 
   
   while(s3==1)
   {
   if(s1==0)
   {
   i++;
   while(s1==0);
   if(i==10)
   {
   i=0;
   }
   }
   if(s2==0)
   {
   i--;
   while(s2==0);
   if(i<0)
   {
   i=9;
   }
   }
   lcd_cmd(s);
   lcd_dat(i+48);
   ms_delay(100);
   }
   if(s3==0)
    {
	i=0;
    s++;
	while(s3==0);
	}
	}
	}


   