#include<reg51.h>
#include<delay.h>
sbit a=P3^3;
sbit b=P3^4;
sbit c=P3^5;
sbit d=P3^6;
sbit R1=P2^0;
sbit R2=P2^1;
sbit R3=P2^2;
sbit R4=P2^3;
sbit led_1=P1^0;
sbit led_2=P1^2;
sbit led_3=P1^4;
sbit led_4=P1^6;
void main()
{
while(1)
{
if(a==0)
{
led_1=~led_1;
R1=~R1;
ms_delay(400);
}
if(b==0)
{
led_2=~led_2;
R2=~R2;
ms_delay(400);
}
if(c==0)
{
led_3=~led_3;
R3=~R3;
ms_delay(400);
}
if(d==0)
{
led_4=~led_4;
R4=~R4;
ms_delay(400);
}
}
}