/* Binary Counting !!*/

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
   P1=0x00; // Initially Set Port 1 to Zero
   while (1)
   {
      P1=P1+1;
      delay(1000);
   }
 }