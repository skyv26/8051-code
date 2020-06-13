#include<reg51.h>
#include<delay.h>
#define motor P0
sbit sw1=P3^0;
sbit sw2=P3^1;
sbit sw3=P3^2;
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
void main()
{
while(1)
{
if(sw1==0)
{
while(sw2==1&&sw3==1)
{
clk(1);
}
}
else if(sw2==0)
{
while(sw1==1&&sw3==1)
{
aclk(1);
}
}
else if(sw3==0)												 
  {
while(sw1==1&&sw2==1)
{
clk(40);
ms_delay(30);
aclk(40);
}
}
}
}


