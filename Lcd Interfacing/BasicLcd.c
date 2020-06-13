/* Binary Counting !!*/

#include <reg51.h>
#define data P2
sbit led=P1^0;
sbit button=P3^0;
sbit Register_State = P3^1;
sbit Read_Write = P3^2;
sbit Enable = P3^3;

void delay(unsigned int ms_Count)
{
    unsigned int i,j;
    for(i=0;i<ms_Count;i++)
    {
        for(j=0;j<100;j++);
    }
}
void lcd_cmd(unsigned char cmd)
{
  Register_State=0;
  Read_Write=0;
  data=cmd;
  Enable=1;
  delay(10);
  Enable=0;
}
void lcd_data(unsigned char Data)
{
  Register_State=1;
  Read_Write=0;
  data=Data;
  Enable=1;
  delay(10);
  Enable=0;
}
void lcd_print(unsigned char *string)
{
   while(*string !='\0')
   {
      lcd_data(*string);
      string++;
   }
}
void lcd_init()
{
   lcd_cmd(0x38);
   lcd_cmd(0x06);
   lcd_cmd(0x0c);
   lcd_cmd(0x01);
}

void main(void)
 { 
      int loop=0xff,checker=128;
      P1=0x00; // Initially Set Port 1 to Zero
      lcd_init();
      lcd_cmd(0x80);
      lcd_print("Aakash Verma");
      while (1)
      {
	if(button==0)
	{
	   led=loop;
	   loop=~loop;
        }
	 
      }
 }