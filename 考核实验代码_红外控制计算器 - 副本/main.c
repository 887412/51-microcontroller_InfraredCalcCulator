#include <reg51.h>
#include "lcd.h"

sbit IRIN=P3^2;   //红外数据接收端口

uchar IrValue[4];	 //存储红外传输后的数据值
uchar Time;			 //用于脉冲信号转数字信号的过程中，衡量时间
uchar times;		 //用于判断红外的多次输入
uchar isIr;			  //是否进入了下一个中断

void delay(uint i)
{
	while(i--);
}

//接受外部输入，来进行运算的函数
void Acessept(void)
{
	//flag用于判断+-*/这四个符号，a代表第一个运算数，b代表第二个运算数，c代表结果，k代表中间变量
	uint a=0,b=0,c=0,k=0;
	uchar flag=0;
	  times = 0;
	 while(times == 0)				//如果times == 0,代表输入的数还在a的范围内
	 {					 			//当按下0x43这个键位代表，a输入完成，进入下一个输入当中
		while(isIr);	 			//防止因为以为一次输入，而造成大量的重复显示，重复判断
	 	switch(IrValue[2])			//对传入的数据位进行判断
	 	{
	 	  case 0x16:				//对相应的键位，对应相应的代表值，输出代表值，对a进行赋值
		  		Lcd1602_WriteData(0x30);	 //余下依旧
				a *= 10;
				a += 1;
				isIr = 1;			 //一次中断对应一次显示赋值
		  	break;
		case 0x0c:
		  		Lcd1602_WriteData(0x30+0x01);
				a *= 10;
				a += 1;
				isIr = 1;	
		  	break;
		case 0x18:
		  		Lcd1602_WriteData(0x30+0x02);
				a *= 10;
				a += 2;
				isIr = 1;	
		  	break;
		case 0x5e:
		  		Lcd1602_WriteData(0x30+0x03);
				a *= 10;
				a += 3;
				isIr = 1;	
		  	break;
		case 0x08:
		  		Lcd1602_WriteData(0x30+0x04);
				a *= 10;
				a += 4;
				isIr = 1;	
		  	break;
		case 0x1c:
		  		Lcd1602_WriteData(0x30+0x05);
				a *= 10;
				a += 5;
				isIr = 1;	
		  	break;
		case 0x5a:
		  		Lcd1602_WriteData(0x30+0x06);
				a *= 10;
				a += 6;
				isIr = 1;	
		  	break;
		case 0x42:
		  		Lcd1602_WriteData(0x30+0x07);
				a *= 10;
				a += 7;
				isIr = 1;			
		  	break;
		case 0x52:
		  		Lcd1602_WriteData(0x30+0x08);
				a *= 10;
				a += 8;
				isIr = 1;	
		  	break;
		case 0x4a:
		  		Lcd1602_WriteData(0x30+0x09);
				a *= 10;
				a += 9;
				isIr = 1;	
		  	break;
		case 0x43:		   //这是进入下一位输入的标志按钮
				times++;	
		  	break;
	//	case 0x40:
	//			Lcd1602_WriteCom(0x0F);
	//			Lcd1602_WriteCom(0x04);
	//			 Lcd1602_WriteData(0x20);
	//			 Lcd1602_WriteCom(0x06);
	//			a = (int)a/10;
	//			isIr = 1;
	//		break;
	 }
	 }
	 delay(100);
	 times = 0;				//归零重新判断
	 IrValue[2] = 0x16;		 //防止由于上一次的结束标志，使得下一次的赋值提前结束
	while(times == 0)
	{
		while(isIr);		 //同样的道理
	 switch(IrValue[2])
	 {
	 	  	case 0x09:
		  		Lcd1602_WriteData(0x2b);
				flag = 0;
				isIr = 1;
				times++;	
		  	break;
		case 0x15:
		  		Lcd1602_WriteData(0x2d);
				flag = 1;
				isIr = 1;
				times++;	
		  	break;
		case 0x19:
		  		Lcd1602_WriteData(0x2a);
				flag = 2;
				isIr = 1;
				times++;	
		  	break;
		case 0x0d:
		  		Lcd1602_WriteData(0x2f);
				flag = 3;
				isIr = 1;
				times++;	
		  	break;   
	 }
	 }
	 delay(1000);
	 times = 0;				  //归零
	 IrValue[2] = 0x45;		  //对上次输入的结束标志进行清零，防止对下一次的操作提前结束
	 while(times == 0)
	 {
	 while(isIr);
	 switch(IrValue[2])
	 {
	 	  case 0x16:			   //同理
		  		Lcd1602_WriteData(0x30);
				b *= 10;
				b += 0;	
				isIr = 1;
		  	break;
		case 0x0c:
		  		Lcd1602_WriteData(0x30+0x01);
				b *= 10;
				b += 1;
				isIr = 1;	
		  	break;
		case 0x18:
		  		Lcd1602_WriteData(0x30+0x02);
				b *= 10;
				b += 2;
				isIr = 1;	
		  	break;
		case 0x5e:
		  		Lcd1602_WriteData(0x30+0x03);
				b *= 10;
				b += 3;
				isIr = 1;	
		  	break;
		case 0x08:
		  		Lcd1602_WriteData(0x30+0x04);
				b *= 10;
				b += 4;
				isIr = 1;	
		  	break;
		case 0x1c:
		  		Lcd1602_WriteData(0x30+0x05);
				b *= 10;
				b += 5;
				isIr = 1;	
		  	break;
		case 0x5a:
		  		Lcd1602_WriteData(0x30+0x06);
				b *= 10;
				b += 6;
				isIr = 1;	
		  	break;
		case 0x42:
		  		Lcd1602_WriteData(0x30+0x07);
				b *= 10;
				b += 7;
				isIr = 1;	
		  	break;
		case 0x52:
		  		Lcd1602_WriteData(0x30+0x08);
				b *= 10;
				b += 8;
				isIr = 1;	
		  	break;
		case 0x4a:
		  		Lcd1602_WriteData(0x30+0x09);
				b *= 10;
				b += 9;
				isIr = 1;	
		  	break;
		case 0x43:
				times++;	
		  	break;
		//case 0x40:
			//	Lcd1602_WriteCom(0x0F);
			//	Lcd1602_WriteCom(0x04);
			//	 Lcd1602_WriteData(0x20);
			//	 Lcd1602_WriteCom(0x06);
			//	a = (int)a/10;
			//	isIr = 1;						//退格键位
		//	break;
	 }
	 }

	 	Lcd1602_WriteCom(0x4f+0x80);
		Lcd1602_WriteCom(0x04);	   //对显示结果进行移位，到第二行末尾
	 	switch(flag)
	 	{
			case 0:
				c = (int)a+b;
				while(c != 0) //对c一位一位的剥离
				{
					Lcd1602_WriteData(0x30 + c%10); //对结果c一位一位输出
					c = (int)c/10;
				}
				Lcd1602_WriteData(0x3d);
				a = 0;
				b = 0;
				c = 0;
				flag = 0;
				times = 0;				//清零，结束这次运算
			 break;
			case 1:
			    //判断结果是大于零还是小于零
				if(a>b)
				{
					c=a-b;
				}
				else
				{
					c=b-a;
				}		
				while(c!=0)	 //一位一位显示
				{
					Lcd1602_WriteData(0x30+c%10);//显示结果的最后一位在0x4f的位置
							c=c/10;//取前面的结果数据	
				}
				if(a<b)	
				{
					Lcd1602_WriteData(0x2d); //显示-号
				}
					Lcd1602_WriteData(0x3d); //显示等于号=
						a=0;
						b=0;
						flag=0;
						times=0;
				break;
			case 2:	
				c=a*b;
				while(c!=0)	 //一位一位显示
				{
					Lcd1602_WriteData(0x30+c%10);//显示结果的最后一位在0x4f的位置
					c=c/10;//取前面的结果数据	
				}
					Lcd1602_WriteData(0x3d); //显示等于号=
					a=0;
					b=0;
					flag=0;
					times=0;
				break;
			case 3:
						k = 0;
				       c=(long)(((float)a/b)*1000);//强制转换为long。
						while(c!=0)	 //一位一位显示
						{
							k++;
							Lcd1602_WriteData(0x30+c%10);//显示结果的最后一位在0x4f的位置
							c=c/10;//取前面的结果数据
							if(k==3)
							{
								Lcd1602_WriteData(0x2e);
								k=0;
							}		
						}
						if(a/b<0)	  //如果a比b小的话那么除的结果最高位是0
						{
							Lcd1602_WriteData(0x30);	
						}
						Lcd1602_WriteData(0x3d); //显示等号
						a=0;
						b=0;
						flag=0;
						times=0;//全部清除为0
					break;
				}
}


//初始化端口，中断开关
void IrInit(void)
{
	IT0 = 1;  //将外部中断方式调节成下降沿触发
	EX0 = 1;  //打开IE中的分布开关EX0
	EA = 1;	  //打开IE中的总开关

	IRIN = 1;  //初始化端口
}

void main(void)
{
	LcdInit();
	IrInit();
	 while(1)
{
	 Acessept();
	 while(IrValue[2] != 0x45);
     Lcd1602_WriteCom(0x01);
}
 }

void ReadIr() interrupt 0
{
	uchar j,k;
	uint err;
	Time=0;
	isIr = 0;					 
	delay(700);	//7ms
	if(IRIN==0)		//确认是否真的接收到正确的信号
	{	 
		
		err=1000;				//1000*10us=10ms,超过说明接收到错误的信号
		/*当两个条件都为真是循环，如果有一个条件为假的时候跳出循环，免得程序出错的时
		侯，程序死在这里*/	
		while((IRIN==0)&&(err>0))	//等待前面9ms的低电平过去  		
		{			
			delay(1);
			err--;
		} 
		if(IRIN==1)			//如果正确等到9ms低电平
		{
			err=500;
			while((IRIN==1)&&(err>0))		 //等待4.5ms的起始高电平过去
			{
				delay(1);
				err--;
			}
			for(k=0;k<4;k++)		//共有4组数据
			{				
				for(j=0;j<8;j++)	//接收一组数据
				{

					err=60;		
					while((IRIN==0)&&(err>0))//等待信号前面的560us低电平过去
					{
						delay(1);
						err--;
					}
					err=500;
					while((IRIN==1)&&(err>0))	 //计算高电平的时间长度。
					{
						delay(10);	 //0.1ms
						Time++;
						err--;
						if(Time>30)
						{
							return;
						}
					}
					IrValue[k]>>=1;	 //k表示第几组数据
					if(Time>=8)			//如果高电平出现大于565us，那么是1
					{
						IrValue[k]|=0x80;
					}
					Time=0;		//用完时间要重新赋值							
				}
			}
		}
		if(IrValue[2]!=~IrValue[3])
		{
			return;
		}
	}			
}