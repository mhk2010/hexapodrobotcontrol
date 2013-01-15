#ifndef DELAY_H
#define DELAY_H

/***********************************************************
	Module Name: TIMEDELAY.h
	Module Date: 3/15/2007                         
	Module Auth: Liangzhe
	
	Description: 
 TIMEDELAY.Cʵ������������������ʱ���ֱ�Ϊ��
	 
  void delay_us();			               ΢�뼶��ʱ����
  void delay_10us(unsigned int M);           10΢�뼶��ʱ����
  void delay_100us(unsigned int M);          100΢�뼶��ʱ����
  void delay_ms(unsigned int M);	           ���뼶��ʱ����
  void delay_10ms(unsigned int M);           10���뼶��ʱ����
  void delay_100ms(unsigned char M);         100���뼶��ʱ����
  void delay_s(unsigned char M);	           �뼶��ʱ����

 TIMEDELAY.C��ʹ��AVRStudio����,void delay_us()�����ж�ʱΪ1us;
 ����΢�뼶��ʱ�������ô˺���ʵ�ֶ�ʱ�������β�M�÷����£�
 ����ʱ50us,����delay_10us(5).ע�Ͳ���Ϊ��������Mȡֵ100,1000,5000ʱ�� 
 AVRStudio������ʵ������ʱ��ΪTIME��ERRORΪ����������
	
	
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

extern void delay_us(void);			               //΢�뼶��ʱ����
extern void delay_10us(unsigned int M);           //10΢�뼶��ʱ����
extern void delay_100us(unsigned int M);          //100΢�뼶��ʱ����
extern void delay_ms(unsigned int M);	           //���뼶��ʱ����
extern void delay_10ms(unsigned int M);           //10���뼶��ʱ����
extern void delay_100ms(unsigned int M);         //100���뼶��ʱ����
extern void delay_s(unsigned int M);	           //�뼶��ʱ����
extern void myDelay(INT32U ulTime);					//��Զ��д��ʱ����

#endif 

