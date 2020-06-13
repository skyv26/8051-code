
		#include<reg51.h>
		#include<delay.h>
		#include<p2lcd.h>
  sbit f1=P1^0;
  sbit b1=P1^1;
  sbit f2=P1^2;
  sbit b2=P1^3;
  sbit fwd=P0^0;
  sbit bwd=P0^1;
  sbit rt=P0^2;
  sbit lt=P0^3;
                #define off 1;
		#define on 0;
			void main()
			{

				lcd_init();
				P0=0xff;
		/*
			lcd_cmd(0x01);
			secdelay(1);
			lcd_cmd(0x80);
			lcd_puts(" Your Welcome ! ");
			secdelay(1);	
			lcd_cmd(0x01);
			ms_delay(200);
			lcd_cmd(0x80);
			lcd_puts(" Some Important ");
			lcd_cmd(0xc0);
			lcd_puts(" Instruction... ");
	
			secdelay(2);
			lcd_cmd(0x01);
			ms_delay(200);
			lcd_cmd(0x80);
lcd_puts(" Hi! I'm a Robo ");
lcd_cmd(0xc0);
lcd_puts("     Car...     ");
secdelay(1);
lcd_cmd(0x01);
ms_delay(200);
lcd_cmd(0x80);
lcd_puts("You Have remote!");
lcd_cmd(0xc0);
lcd_puts(" In YOur Hand! ");
secdelay(1);
lcd_cmd(0x01);
ms_delay(200);
lcd_cmd(0x80);
lcd_puts(" as you can see ");
lcd_cmd(0xc0);
lcd_puts("there're 4 keys.");
ms_delay(700);
lcd_cmd(0x01);
lcd_cmd(0x80);
lcd_puts("  ...on remote  ");
ms_delay(700);
lcd_cmd(0x80);
lcd_puts(" That's         ");
ms_delay(800);
lcd_cmd(0x80);
lcd_puts(" That's A       ");
ms_delay(800);
lcd_cmd(0x80);
lcd_puts(" That's A,B     ");
ms_delay(800);
lcd_cmd(0x80);
lcd_puts(" That's A,B,C   ");
ms_delay(800);
lcd_cmd(0x80);
lcd_puts(" That's A,B,C,D ");
ms_delay(800);
lcd_cmd(0x01);
secdelay(1);
lcd_cmd(0x80);
lcd_puts(" Press 'A' for  ");
lcd_cmd(0xc0);
lcd_puts("  forward move  ");
ms_delay(800);
lcd_cmd(0x80);
lcd_puts(" Press 'A' for  ");
lcd_cmd(0xc0);
lcd_puts("  forward move. ");
ms_delay(800);
lcd_cmd(0x80);
lcd_puts(" Press 'A' for  ");
lcd_cmd(0xc0);
lcd_puts("  forward move..");
ms_delay(800);
lcd_cmd(0x01);
ms_delay(200);
lcd_cmd(0x80);
lcd_puts(" Press 'B' for  ");
lcd_cmd(0xc0);
lcd_puts(" Backward move. ");
ms_delay(800);
lcd_cmd(0x80);
lcd_puts(" Press 'B' for  ");
lcd_cmd(0xc0);
lcd_puts(" Backward move..");
lcd_cmd(0x01);
ms_delay(200);
lcd_cmd(0x80);
lcd_puts(" Press 'C' for  ");
lcd_cmd(0xc0);
lcd_puts("   Right move   ");
ms_delay(800);
lcd_cmd(0x80);
lcd_puts(" Press 'C' for  ");
lcd_cmd(0xc0);
lcd_puts("   Right move.  ");
ms_delay(800);
lcd_cmd(0x80);
lcd_puts(" Press 'C' for  ");
lcd_cmd(0xc0);
lcd_puts("   Right move.. ");
ms_delay(800);
lcd_cmd(0x01);
ms_delay(200);
lcd_cmd(0x80);
lcd_puts(" Press 'D' for  ");
lcd_cmd(0xc0);
lcd_puts("   Left move   ");
ms_delay(800);
lcd_cmd(0x80);
lcd_puts(" Press 'D' for  ");
lcd_cmd(0xc0);
lcd_puts("   Left move.   ");
ms_delay(800);
lcd_cmd(0x80);
lcd_puts(" Press 'D' for  ");
lcd_cmd(0xc0);
lcd_puts("   Left move..  ");
ms_delay(800);
lcd_cmd(0x80);
lcd_puts(" Press 'D' for  ");
lcd_cmd(0xc0);
lcd_puts("   Left move... ");
ms_delay(800);*/
lcd_cmd(0x01);
while(1)
{
if(fwd==0)				  
{
/*lcd_cmd(0x80);
lcd_puts(" Moving Forward ");
lcd_cmd(0xc0);
lcd_puts("->              "); */
f1=on;
f2=on;
b1=off;
b2=off;	 
ms_delay(30);/*
lcd_cmd(0xc0);
lcd_puts("     ->         ");
ms_delay(50);
lcd_cmd(0xc0);
lcd_puts("         ->     ");
ms_delay(50);
lcd_cmd(0xc0);
lcd_puts("              ->");
ms_delay(50);			*/
}
else if(bwd==0)
{						  /*
lcd_cmd(0x80);
lcd_puts("Moving Backward ");
lcd_cmd(0xc0);
lcd_puts("              <-");*/
f1=off;
f2=off;
b1=on;
b2=on;
ms_delay(30);/*
lcd_cmd(0xc0);
lcd_puts("         <-     ");
ms_delay(50);
lcd_cmd(0xc0);
lcd_puts("     <-         ");
ms_delay(50);
lcd_cmd(0xc0);
lcd_puts("<-              "); */
ms_delay(50);
}			 
else if(rt==0)
{			   /*
lcd_cmd(0x80);
lcd_puts("  Moving Right  ");
lcd_cmd(0xc0);
lcd_puts("     <<@@>>     ");	*/
f1=on;
f2=off;
b1=off;
b2=off;
ms_delay(30); /*
lcd_cmd(0xc0);
lcd_puts("     << @  >>   ");
ms_delay(50);
lcd_cmd(0xc0);
lcd_puts("     <<@@    >> ");
ms_delay(50);
lcd_cmd(0xc0);
lcd_puts("     << @     >>");
ms_delay(50);	*/
}
else if(lt==0)
{				  /*
lcd_cmd(0x80);	  
lcd_puts("  Moving Left.  ");
lcd_cmd(0xc0);
lcd_puts("     <<@@>>     "); */
f1=off;
f2=on;
b1=off;
b2=off;
ms_delay(30);  /*
lcd_cmd(0xc0);
lcd_puts("    << @ >>     ");
ms_delay(50);
lcd_cmd(0xc0);
lcd_puts(" <<    @@>>     ");
ms_delay(50);
lcd_cmd(0xc0);
lcd_puts("<<     @ >>     ");
ms_delay(50);	 */
}
else
{
lcd_cmd(0x80);
lcd_puts(" Let's START... ");
lcd_cmd(0xc0);
lcd_puts("                ");
f1=off;
f2=off; 
b1=off;
b2=off;
while(fwd&&bwd&&rt&&lt==1);
}
}
}