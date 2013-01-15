#ifndef DELAY_H
#define DELAY_H

/***********************************************************
	Module Name: TIMEDELAY.h
	Module Date: 3/15/2007                         
	Module Auth: Liangzhe
	
	Description: 
 TIMEDELAY.C实现了六个级别的软件延时，分别为：
	 
  void delay_us();			               微秒级延时程序
  void delay_10us(unsigned int M);           10微秒级延时程序
  void delay_100us(unsigned int M);          100微秒级延时程序
  void delay_ms(unsigned int M);	           毫秒级延时程序
  void delay_10ms(unsigned int M);           10毫秒级延时程序
  void delay_100ms(unsigned char M);         100毫秒级延时程序
  void delay_s(unsigned char M);	           秒级延时程序

 TIMEDELAY.C中使用AVRStudio仿真,void delay_us()函数中定时为1us;
 后续微秒级延时函数调用此函数实现定时。函数形参M用法如下：
 如延时50us,调用delay_10us(5).注释部分为误差分析，M取值100,1000,5000时， 
 AVRStudio仿真中实际运行时间为TIME，ERROR为计算所得误差。
	
	
    Revision History:
    Date        Rel Ver.    Notes
    3/15/2007		1.0			Module created

***********************************************************/

/*----------------Includes---------------*/

/*------------Local Variables----------- */

/*---------Structures and Typedefs-------*/					

/*-----------Extern Variables -----------*/

/*---------------Defines-----------------*/

/*----------extern variables-------------*/

/*-----External Function Prototypes------*/

extern void delay_us(void);			               //微秒级延时程序
extern void delay_10us(unsigned int M);           //10微秒级延时程序
extern void delay_100us(unsigned int M);          //100微秒级延时程序
extern void delay_ms(unsigned int M);	           //毫秒级延时程序
extern void delay_10ms(unsigned int M);           //10毫秒级延时程序
extern void delay_100ms(unsigned int M);         //100毫秒级延时程序
extern void delay_s(unsigned int M);	           //秒级延时程序
extern void myDelay(INT32U ulTime);					//致远自写延时函数

#endif 

