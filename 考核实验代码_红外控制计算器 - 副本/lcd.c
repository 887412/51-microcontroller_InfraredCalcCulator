#include "lcd.h"

//��51��Ƭ����д��1ms�µ���ʱ����
void Lcd1602_Delay1ms(uint c)
{
	uchar a,b;
	for(; c>0; c--)
	{
		for(b=199; b>0; b--)
		{
			for(a=1; a>0; a--);
		}
	}
}

//��Lcd1602��д��8λ��ָ�����
void Lcd1602_WriteCom(uchar com)
{
	LCD1602_E = 0;
	LCD1602_RS = 0;
	LCD1602_RW = 0;	 //��оƬʹ�ܣ�����ģʽΪָ��д��ģʽ


	LCD1602_DATA_PORT = com;  //����ָ��
	Lcd1602_Delay1ms(1);

	LCD1602_E = 1;			//д��ʱ��
	Lcd1602_Delay1ms(5);
	LCD1602_E = 0;
}

//��Lcd1602��д��8λ������
void Lcd1602_WriteData(uchar dat)
{
	LCD1602_E = 0; //ʹ������
	LCD1602_RS = 1;
	LCD1602_RW = 0;

	LCD1602_DATA_PORT = dat;
	Lcd1602_Delay1ms(1);

	LCD1602_E = 1;	   //д��ʱ��
	Lcd1602_Delay1ms(5);
	LCD1602_E = 0;

}

//��ʼ����lcd1602���溯��
void LcdInit()
{
	Lcd1602_WriteCom(0x38);
	Lcd1602_Delay1ms(5);
	Lcd1602_WriteCom(0x38);
	Lcd1602_Delay1ms(5);
	Lcd1602_WriteCom(0x38);
	Lcd1602_Delay1ms(5);	 //ȷ����ʾ��ʼ���ɹ� ����ʾ������λ��������ֵ

	Lcd1602_WriteCom(0x0c);//����ʾ������ʾ���
	Lcd1602_WriteCom(0x06);//дһ��ָ���1
	Lcd1602_WriteCom(0x01);//����
	Lcd1602_WriteCom(0x80);//��������ָ�����
}