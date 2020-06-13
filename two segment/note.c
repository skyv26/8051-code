#include<reg51.h>
#include<delay.h>
#define S P1
//#define R P0
#define on 0
#define off 1
sbit relay=P0^1;
sbit s1=P3^0;
sbit s2=P3^1;
sbit s3=P3^2;
sbit E1=P3^3;
sbit E2=P3^4;
unsigned char A[10]={0X81,0XB7,0XC2,0X92,0XB4,0X98,0X88,0XB3,0X80,0XB0};
void main()
{
bit f;
signed char o,t,a,b,c;
P0=0;
while(1)
{
if(s1==on)
	{
	o++;		  
    if(o>9)
		{
		t++;
		o=0;
		if(t>9)
			{
			t=0;
			}
		}
	while(s1==on)
	{

E1=on;		
E2=off;
S=A[o];
ms_delay(10);
E1=off;
E2=on;
S=A[t];
ms_delay(10);
}
f=on;
	}
	if(s2==on)
	{
	o--;		  
    if(o<0)
		{
		t--;
		o=9;
		if(t<0)
			{
			t=9;
			}
		}
	while(s2==on)
	{
	
E1=on;		
E2=off;
S=A[o];
ms_delay(10);
E1=off;
E2=on;
S=A[t];
ms_delay(10);
} 
f=off;
	}
E1=on;		
E2=off;
S=A[o];
ms_delay(10);
E1=off;
E2=on;
S=A[t];
ms_delay(10);


	if(s3==on)
    {
	if(f==on)
	{
	for(c=t;c<10;c++)
	{
	for(b=o;b<10;b++)
	{
	for(a=0;a<50;a++)
	{	
E1=on;		
E2=off;
S=A[b];
ms_delay(10);
E1=off;
E2=on;
S=A[c];
ms_delay(10);
}
}
o=0;
}
t=0;
}
else
{
	for(c=t;c>=0;c--)
	{
	for(b=o;b>=0;b--)
	{
	for(a=0;a<50;a++)
	{	
E1=on;		
E2=off;
S=A[b];
ms_delay(10);
E1=off;
E2=on;
S=A[c];
ms_delay(10);
}
}
o=9;
}
t=9;

}
relay=1;
P1=0xfe;
while(1)
{
E1=E2=0;
P1=P1<<1;
secdelay(1);
}
}
}
}