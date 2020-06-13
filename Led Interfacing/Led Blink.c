#include <reg51.h>
#include <stdio.h>
sbit led=P1^0;
void delay(unsigned int ms_Count)
{
    unsigned int i,j;
    for(i=0;i<ms_Count;i++)
    {
        for(j=0;j<100;j++);
    }
}
void main(void)
 { 
   // Write your code here
   P1=0x00;      // Initially Set Port 1 to Zero
   while (1)
   {
      led=0;
      delay(1000);
      led=1;
      delay(1000);
   }
 }