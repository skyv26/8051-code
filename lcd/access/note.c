#include<reg51.h>
#include<delay.h>
#include<lcd.h>
#include<stpr.h>
#define adc P2
sbit SC=P3^3;
sbit s1=P3^0;
sbit s2=P3^1;
sbit s3=P3^2;
sbit bulb=P0^1;
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
signed char A,B,C,D;
//bit f;
P0=0;
P1=0xff;
lcd_init();
while(1)
{  
   A=B=C=D=0;
   lcd_cmd(0x01);
   lcd_cmd(0x84);
   lcd_puts("PASSWORD");
   while(s3==1)
   {	
   if(s1==0)
	   {
	   A++;
	   }
	   while(s1==0);
	   if(A==10)
		   {
		   A=0;
		   }
   if(s2==0)
	   {
	  A--;
	  }
	   while(s2==0);
	   if(A<0)
		   {
		   A=9;
		   }
   lcd_cmd(0xc0);
   lcd_dat(A+48);
   }
   lcd_cmd(0xc0);
   lcd_dat('*');
   ms_delay(500);
 while(s3==1)
   {
   if(s1==0)
	   {
	   B++;
	   while(s1==0);
	   if(B==10)
		   {
		   B=0;
		   }
	   }
   if(s2==0)
	   {
	  B--;
	   while(s2==0);
	   if(B<0)
		   {
		   B=9;
		   }
	    
	   }
   lcd_cmd(0xc1);
   lcd_dat(B+48);
   }
   lcd_cmd(0xc1);
   lcd_dat('*');
   ms_delay(500);
   while(s3==1)
   {
   if(s1==0)
	   {
	   C++;
	   while(s1==0);
	   if(C==10)
		   {
		   C=0;
		   }
	   }
   if(s2==0)
	   {
	  C--;
	   while(s2==0);
	   if(C<0)
		   {
		    C=9;
		   }
	    
	   }
   lcd_cmd(0xc2);
   lcd_dat(C+48);
   }
   lcd_cmd(0xc2);
   lcd_dat('*');
   ms_delay(500);
   while(s3==1)
   {
   if(s1==0)
	   {
	   D++;
	   while(s1==0);
	   if(D==10)
		   {
		   D=0;
		   }
	   }
   if(s2==0)
	   {
	  D--;
	   while(s2==0);
	   if(D<0)
		   {
		   D=9;
		   }
	    
	   }
   lcd_cmd(0xc3);
   lcd_dat(D+48); 
   }
   lcd_cmd(0xc3);
   lcd_dat('*');
   ms_delay(500);
  
   if(A==1 && B==2 && C==3 && D==4)
   {
    lcd_cmd(0x01);
	lcd_cmd(0x84);
	lcd_puts("CORRECT!");
	secdelay(2);
	}
	else
	{ 
	lcd_cmd(0x01);
	 secdelay(1);
	lcd_cmd(0x81);
	lcd_puts("INCORRECT -_-");
	lcd_cmd(0xC2);
	lcd_puts("Try Again!");
	secdelay(1);
	while(s1!=0);
	lcd_cmd(0x01);
	ms_delay(500);
	A=B=C=D=0;
   lcd_cmd(0x01);
   lcd_cmd(0x84);
   lcd_puts("PASSWORD");
   while(s3==1)
   {	
   if(s1==0)
	   {
	   A++;
	   }
	   while(s1==0);
	   if(A==10)
		   {
		   A=0;
		   }
   if(s2==0)
	   {
	  A--;
	  }
	   while(s2==0);
	   if(A<0)
		   {
		   A=9;
		   }
   lcd_cmd(0xc0);
   lcd_dat(A+48);
   }
   lcd_cmd(0xc0);
   lcd_dat('*');
   ms_delay(500);
 while(s3==1)
   {
   if(s1==0)
	   {
	   B++;
	   while(s1==0);
	   if(B==10)
		   {
		   B=0;
		   }
	   }
   if(s2==0)
	   {
	  B--;
	   while(s2==0);
	   if(B<0)
		   {
		   B=9;
		   }
	    
	   }
   lcd_cmd(0xc1);
   lcd_dat(B+48);
   }
   lcd_cmd(0xc1);
   lcd_dat('*');
   ms_delay(500);
   while(s3==1)
   {
   if(s1==0)
	   {
	   C++;
	   while(s1==0);
	   if(C==10)
		   {
		   C=0;
		   }
	   }
   if(s2==0)
	   {
	  C--;
	   while(s2==0);
	   if(C<0)
		   {
		    C=9;
		   }
	    
	   }
   lcd_cmd(0xc2);
   lcd_dat(C+48);
   }
   lcd_cmd(0xc2);
   lcd_dat('*');
   ms_delay(500);
   while(s3==1)
   {
   if(s1==0)
	   {
	   D++;
	   while(s1==0);
	   if(D==10)
		   {
		   D=0;
		   }
	   }
   if(s2==0)
	   {
	  D--;
	   while(s2==0);
	   if(D<0)
		   {
		   D=9;
		   }
	    
	   }
   lcd_cmd(0xc3);
   lcd_dat(D+48); 
   }
   lcd_cmd(0xc3);
   lcd_dat('*');
   ms_delay(500);
	}
	lcd_cmd(0x01);
   A=B=C=D=0;
   lcd_cmd(0x80);
   lcd_puts("  We have two.  ");
   lcd_cmd(0xc0);
   lcd_puts("   devices...   ");
   secdelay(3);
   lcd_cmd(0x01);
   ms_delay(300);
   lcd_cmd(0x80);
   lcd_puts("A stepper motor.");
    secdelay(1);
   lcd_cmd(0x01);
   ms_delay(300);
   lcd_cmd(0x80);
   lcd_puts("    Bulb....    ");
   secdelay(1);
   lcd_cmd(0x01);
   ms_delay(500);
   lcd_cmd(0x80);
   lcd_puts("  ** Press 1 ** ");
     lcd_cmd(0xc0);
   lcd_puts("For Steppr Motor");
   secdelay(2);
   lcd_cmd(0x80);
   lcd_puts("                ");
    lcd_cmd(0x80);
   lcd_puts("  ** Press 2 ** ");
   lcd_cmd(0xc0);
   lcd_puts("                ");
   lcd_cmd(0xc0);
   lcd_puts("    For Bulb    ");
   secdelay(2);
   lcd_cmd(0x01);
   secdelay(1);
   lcd_cmd(0x80);
   lcd_puts("   Enter no..   ");
   while(s3==1)
   {	
   if(s1==0)
	   {
	   A++;
	   }
	   while(s1==0);
	   if(A==10)
		   {
		   A=0;
		   }
   if(s2==0)
	   {
	  A--;
	  }
	   while(s2==0);
	   if(A<0)
		   {
		   A=9;
		   }
   lcd_cmd(0xc0);
   lcd_dat(A+48);
   }
   lcd_cmd(0xc0);
   lcd_dat('*');
   ms_delay(500);
   	
	if(A==1)
   {
   lcd_cmd(0x01);
   secdelay(1);
   lcd_cmd(0x80);
   lcd_puts(" 0 for clkwise. ");
    lcd_cmd(0xc0);
   lcd_puts(" 1 for aclkwise ");
   secdelay(2);
   lcd_cmd(0x01);
   ms_delay(500);
   lcd_cmd(0x80);
   lcd_puts("  enter key.... ");
   while(s3==1)
   {	
   if(s1==0)
	   {
	   A++;
	   }
	   while(s1==0);
	   if(A==10)
		   {
		   A=0;
		   }
   if(s2==0)
	   {
	  A--;
	  }
	   while(s2==0);
	   if(A<0)
		   {
		   A=9;
		   }
   lcd_cmd(0xc0);
   lcd_dat(A+48);
   }
   lcd_cmd(0xc0);
   lcd_dat('*');
   ms_delay(500);
   if(A==0)
   {
    lcd_cmd(0x01);
	secdelay(1);	 
   lcd_cmd(0x80);
   lcd_puts("    Loading     ");
   ms_delay(500);
   lcd_cmd(0x80);
   lcd_puts("    Loading.     ");
   ms_delay(500);
    lcd_cmd(0x80);
   lcd_puts("    Loading..     ");
   ms_delay(500);
	 while(s1!=0)
    {
	lcd_cmd(0x80);
	lcd_puts(" clk motor on.. ");
	clk(1);
    }
	}
	     	else if(A==1)
		     {
	               lcd_cmd(0x01);
	               secdelay(1);
				   lcd_cmd(0x80);
   lcd_puts("    Loading     ");
   ms_delay(500);
   lcd_cmd(0x80);
   lcd_puts("    Loading.     ");
   ms_delay(500);
    lcd_cmd(0x80);
   lcd_puts("    Loading..     ");
   ms_delay(500);
	               while(s1!=0)
                    {
	                  lcd_cmd(0x80);
                   	  lcd_puts(" aclk motor on..");
	                  aclk(1);
					  }
              
					}
					}
             else if(A==2)
		     {
	               lcd_cmd(0x01);
	               secdelay(1);
				   lcd_cmd(0x80);
   lcd_puts("    Loading     ");
   ms_delay(500);
   lcd_cmd(0x80);
   lcd_puts("    Loading.     ");
   ms_delay(500);
    lcd_cmd(0x80);
   lcd_puts("    Loading..     ");
   ms_delay(500);
	               while(s1!=0)
                    {
	                  lcd_cmd(0x80);
                   	  lcd_puts("   Bulb on...   ");
	                  bulb=1;
					  while(s1!=0);
					   }
					  while(s1==0)
              		 {
					 motor=0;
					 }		 
					}
		else
		{ 
			                 	   lcd_cmd(0x80);
                 				   lcd_puts("  Wrong Choice  ");
								   lcd_cmd(0xc0);
                 				   lcd_puts("  Try Again !!  ");
								   secdelay(1);
								   lcd_cmd(0xc0);
								   lcd_puts("                ");
								   secdelay(1);
								   lcd_cmd(0xc0);
                 				   lcd_puts("  Try Again !!  ");
								   secdelay(1);
								   lcd_cmd(0xc0);
								   lcd_puts("                ");
								   secdelay(1);
                                   while(s1!=0);
								   ms_delay(500);

	}
	}
	}	
   