
#ifndef 		_LCD_H_
#define			_LCD_H_

#include <reg51.h>
 
#define LCD1602_DATA_PORT 		P0	  //lcd1602的数据和指令输入端口

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif							   //问题为啥在这里使用typedef重定义不行
//定义其中，开关，指令和读写控制端口
sbit LCD1602_E = P2^7;
sbit LCD1602_RW = P2^5;
sbit LCD1602_RS = P2^6;

/***************
	函数声明
*********/

//在51单片机中写入1ms下的延时程序
void Lcd1602_Delay1ms(uint c);

//在Lcd1602中写入8位的指令，命令
void Lcd1602_WriteCom(uchar com);

//在Lcd1602中写入8位的数据
void Lcd1602_WriteData(uchar dat);

//初始化，lcd1602界面函数
void LcdInit();
#endif


