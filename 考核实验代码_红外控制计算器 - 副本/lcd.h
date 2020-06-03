
#ifndef 		_LCD_H_
#define			_LCD_H_

#include <reg51.h>
 
#define LCD1602_DATA_PORT 		P0	  //lcd1602�����ݺ�ָ������˿�

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif							   //����Ϊɶ������ʹ��typedef�ض��岻��
//�������У����أ�ָ��Ͷ�д���ƶ˿�
sbit LCD1602_E = P2^7;
sbit LCD1602_RW = P2^5;
sbit LCD1602_RS = P2^6;

/***************
	��������
*********/

//��51��Ƭ����д��1ms�µ���ʱ����
void Lcd1602_Delay1ms(uint c);

//��Lcd1602��д��8λ��ָ�����
void Lcd1602_WriteCom(uchar com);

//��Lcd1602��д��8λ������
void Lcd1602_WriteData(uchar dat);

//��ʼ����lcd1602���溯��
void LcdInit();
#endif


