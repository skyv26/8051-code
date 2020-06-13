#include<reg51.h>
#include<delay.h>
#define data P2
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
signed char i,n;
bit f;
P0=0;
P1=0;
lcd_init();
lcd_cmd(0x80);
lcd_puts("COUNTING!");
while(1)
{ 
   lcd_cmd(0xc0);
   lcd_dat(i+48);
   ms_delay(100);
   if(s1==0)
   {
   i++;
   while(s1==0);
   if(i==10)
   {
   i=0;
   }
   f=1;
   }
   if(s2==0)
   {
   i--;
   while(s2==0);
   if(i==255)
   {
   i=9;
   }
   f=0;
   }
   if(s3==0)
   {
   if(f==1) 
   {
   for(n=i;n<10;n++)  
   {
   lcd_cmd(0xc0);
   lcd_dat(n+48);
   ms_delay(300);
   }
   for(n=0;n<=i;n++)
   	{
	lcd_cmd(0xc0);
   	lcd_dat(n+48);
   	ms_delay(300);
   
	}
   }
   else if(f==0)
   {
   for(n=i;n>=0;n--)
   {
   lcd_cmd(0xc0);
   lcd_dat(n+48);
   ms_delay(300);
   }

   for(n=9;n>=i;n--)
   	{
	lcd_cmd(0xc0);
   	lcd_dat(n+48);
   	ms_delay(300);
   
	}
   }
  
   }
}
}
					    