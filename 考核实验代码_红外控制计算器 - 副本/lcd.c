#include "lcd.h"

//在51单片机中写入1ms下的延时程序
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

//在Lcd1602中写入8位的指令，命令
void Lcd1602_WriteCom(uchar com)
{
	LCD1602_E = 0;
	LCD1602_RS = 0;
	LCD1602_RW = 0;	 //让芯片使能，调节模式为指令写入模式


	LCD1602_DATA_PORT = com;  //输入指令
	Lcd1602_Delay1ms(1);

	LCD1602_E = 1;			//写入时序
	Lcd1602_Delay1ms(5);
	LCD1602_E = 0;
}

//在Lcd1602中写入8位的数据
void Lcd1602_WriteData(uchar dat)
{
	LCD1602_E = 0; //使能清零
	LCD1602_RS = 1;
	LCD1602_RW = 0;

	LCD1602_DATA_PORT = dat;
	Lcd1602_Delay1ms(1);

	LCD1602_E = 1;	   //写入时许
	Lcd1602_Delay1ms(5);
	LCD1602_E = 0;

}

//初始化，lcd1602界面函数
void LcdInit()
{
	Lcd1602_WriteCom(0x38);
	Lcd1602_Delay1ms(5);
	Lcd1602_WriteCom(0x38);
	Lcd1602_Delay1ms(5);
	Lcd1602_WriteCom(0x38);
	Lcd1602_Delay1ms(5);	 //确保显示初始化成功 ，显示行数，位数，点阵值

	Lcd1602_WriteCom(0x0c);//开显示，不显示光标
	Lcd1602_WriteCom(0x06);//写一个指针加1
	Lcd1602_WriteCom(0x01);//清屏
	Lcd1602_WriteCom(0x80);//设置数据指针起点
}