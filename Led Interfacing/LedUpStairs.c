/* Binary Counting !!*/

#include <reg51.h>
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
      int loop=1;
      P1=0x00; // Initially Set Port 1 to Zero
      while (1)
      {
	 if(loop>128)
	 {
	    loop=1;
	 }
	 P1=loop;
         delay(1000);
	 loop*=2;
      }
 }