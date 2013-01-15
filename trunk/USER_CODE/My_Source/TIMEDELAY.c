#include "..\..\config.h"


/*********************************************************************************************************
** Function name:       myDelay
** Descriptions:        软件延时
** input parameters:    无
** output parameters:   无
** Returned value:      无
*********************************************************************************************************/
void myDelay(INT32U ulTime)
{
    INT32U i;
    
    i = 0;
    while (ulTime--) {
      for (i = 0; i < 5000; i++);
    }
}

/*********************************delay_us()************************************
 ERROR=0
********************************************************************************/
void delay_us()                    
{
 _nop_();
 _nop_();
 _nop_();
 _nop_();
 _nop_();
 _nop_();
 _nop_();
}

/*********************************delay_10us(unsigned int M)******************
M=1,   TIME=13.75,   ERROR=37.5%;  （注意!!!误差较大，请选用其他量级）
M=10,  TIME=103.75,  ERROR=3.75%;   （注意!!!误差较大，请选用其他量级）
M=100, TIME=1003.75, ERROR=0.375%;
M=1000,TIME=10004.12,ERROR=0.0412%; 
M=5000,TIME=50006.12,ERROR=0.0122%;
******************************************************************************/
void delay_10us(unsigned int M)   
{  
   unsigned int i;
   while(M--)
   { 
   	 unsigned int i=7;
     while(i--)
	   {
		 delay_us();
		}
	  _nop_();
	  _nop_();
	  _nop_();
   }
}

/*********************************delay_100us(unsigned int M)***********
M=1,   TIME=103.75,   ERROR=3.75%;  （注意!!!误差较大，请选用其他量级）
M=10,  TIME=1003.75,  ERROR=0.375%;
M=100, TIME=10003.75, ERROR=0.0375%;
M=1000,TIME=100004.12,ERROR=0.00412%; 
M=5000,TIME=500006.12,ERROR=0.00122%;
************************************************************************/

void delay_100us(unsigned int M)  
{   
    unsigned int i;
    while(M--)
	{
	  unsigned int i=79;
	  while(i--)                
        {
		 delay_us();
		 }
   	_nop_();
    _nop_();
	  _nop_();
   }
}

/*********************************delay_ms(unsigned int M)***************************
M=1,   TIME=1003.75,   ERROR=0.375%; 
M=10,  TIME=10003.75,  ERROR=0.0375%;
M=100, TIME=100003.75, ERROR=0.00375%;
M=1000,TIME=1000004.12,ERROR=0.000412%; 
M=5000,TIME=5000006.12,ERROR=0.000122%;
***********************************************************************/
void delay_ms(unsigned int M) 
{  unsigned int i;
	while(M--)
	{ unsigned int i=798;
		while(i--)                
        {
		 delay_us();
		 }
    _nop_();
    _nop_();
	  _nop_();
	  _nop_();
    _nop_();
	  _nop_();
	  _nop_();
    _nop_();
	  _nop_();
	  _nop_();
    _nop_();
	  _nop_();
	  _nop_();
    _nop_();
	  _nop_();
	  _nop_();
    _nop_();
	    }
}



/*********************************delay_10ms(unsigned int M)***************************/
void delay_10ms(unsigned int  M) 
{
	while(M)
	{
	  delay_ms(10);
	  M--;
	}
}



/*********************************delay_100ms(unsigned int M)***************************/
void delay_100ms(unsigned int  M) 
{
	while(M)
	{
	 delay_ms(100);
	 M--;
	}
}



/*********************************delay_s(unsigned int M)***************************/
void delay_s(unsigned int M) 
{
while(M)
	{
		delay_ms(1000);
		M--;
	}
}
