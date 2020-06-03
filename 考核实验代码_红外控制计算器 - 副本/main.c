#include <reg51.h>
#include "lcd.h"

sbit IRIN=P3^2;   //�������ݽ��ն˿�

uchar IrValue[4];	 //�洢���⴫��������ֵ
uchar Time;			 //���������ź�ת�����źŵĹ����У�����ʱ��
uchar times;		 //�����жϺ���Ķ������
uchar isIr;			  //�Ƿ��������һ���ж�

void delay(uint i)
{
	while(i--);
}

//�����ⲿ���룬����������ĺ���
void Acessept(void)
{
	//flag�����ж�+-*/���ĸ����ţ�a�����һ����������b����ڶ�����������c��������k�����м����
	uint a=0,b=0,c=0,k=0;
	uchar flag=0;
	  times = 0;
	 while(times == 0)				//���times == 0,���������������a�ķ�Χ��
	 {					 			//������0x43�����λ����a������ɣ�������һ�����뵱��
		while(isIr);	 			//��ֹ��Ϊ��Ϊһ�����룬����ɴ������ظ���ʾ���ظ��ж�
	 	switch(IrValue[2])			//�Դ��������λ�����ж�
	 	{
	 	  case 0x16:				//����Ӧ�ļ�λ����Ӧ��Ӧ�Ĵ���ֵ���������ֵ����a���и�ֵ
		  		Lcd1602_WriteData(0x30);	 //��������
				a *= 10;
				a += 1;
				isIr = 1;			 //һ���ж϶�Ӧһ����ʾ��ֵ
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
		case 0x43:		   //���ǽ�����һλ����ı�־��ť
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
	 times = 0;				//���������ж�
	 IrValue[2] = 0x16;		 //��ֹ������һ�εĽ�����־��ʹ����һ�εĸ�ֵ��ǰ����
	while(times == 0)
	{
		while(isIr);		 //ͬ���ĵ���
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
	 times = 0;				  //����
	 IrValue[2] = 0x45;		  //���ϴ�����Ľ�����־�������㣬��ֹ����һ�εĲ�����ǰ����
	 while(times == 0)
	 {
	 while(isIr);
	 switch(IrValue[2])
	 {
	 	  case 0x16:			   //ͬ��
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
			//	isIr = 1;						//�˸��λ
		//	break;
	 }
	 }

	 	Lcd1602_WriteCom(0x4f+0x80);
		Lcd1602_WriteCom(0x04);	   //����ʾ���������λ�����ڶ���ĩβ
	 	switch(flag)
	 	{
			case 0:
				c = (int)a+b;
				while(c != 0) //��cһλһλ�İ���
				{
					Lcd1602_WriteData(0x30 + c%10); //�Խ��cһλһλ���
					c = (int)c/10;
				}
				Lcd1602_WriteData(0x3d);
				a = 0;
				b = 0;
				c = 0;
				flag = 0;
				times = 0;				//���㣬�����������
			 break;
			case 1:
			    //�жϽ���Ǵ����㻹��С����
				if(a>b)
				{
					c=a-b;
				}
				else
				{
					c=b-a;
				}		
				while(c!=0)	 //һλһλ��ʾ
				{
					Lcd1602_WriteData(0x30+c%10);//��ʾ��������һλ��0x4f��λ��
							c=c/10;//ȡǰ��Ľ������	
				}
				if(a<b)	
				{
					Lcd1602_WriteData(0x2d); //��ʾ-��
				}
					Lcd1602_WriteData(0x3d); //��ʾ���ں�=
						a=0;
						b=0;
						flag=0;
						times=0;
				break;
			case 2:	
				c=a*b;
				while(c!=0)	 //һλһλ��ʾ
				{
					Lcd1602_WriteData(0x30+c%10);//��ʾ��������һλ��0x4f��λ��
					c=c/10;//ȡǰ��Ľ������	
				}
					Lcd1602_WriteData(0x3d); //��ʾ���ں�=
					a=0;
					b=0;
					flag=0;
					times=0;
				break;
			case 3:
						k = 0;
				       c=(long)(((float)a/b)*1000);//ǿ��ת��Ϊlong��
						while(c!=0)	 //һλһλ��ʾ
						{
							k++;
							Lcd1602_WriteData(0x30+c%10);//��ʾ��������һλ��0x4f��λ��
							c=c/10;//ȡǰ��Ľ������
							if(k==3)
							{
								Lcd1602_WriteData(0x2e);
								k=0;
							}		
						}
						if(a/b<0)	  //���a��bС�Ļ���ô���Ľ�����λ��0
						{
							Lcd1602_WriteData(0x30);	
						}
						Lcd1602_WriteData(0x3d); //��ʾ�Ⱥ�
						a=0;
						b=0;
						flag=0;
						times=0;//ȫ�����Ϊ0
					break;
				}
}


//��ʼ���˿ڣ��жϿ���
void IrInit(void)
{
	IT0 = 1;  //���ⲿ�жϷ�ʽ���ڳ��½��ش���
	EX0 = 1;  //��IE�еķֲ�����EX0
	EA = 1;	  //��IE�е��ܿ���

	IRIN = 1;  //��ʼ���˿�
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
	if(IRIN==0)		//ȷ���Ƿ���Ľ��յ���ȷ���ź�
	{	 
		
		err=1000;				//1000*10us=10ms,����˵�����յ�������ź�
		/*������������Ϊ����ѭ���������һ������Ϊ�ٵ�ʱ������ѭ������ó�������ʱ
		�������������*/	
		while((IRIN==0)&&(err>0))	//�ȴ�ǰ��9ms�ĵ͵�ƽ��ȥ  		
		{			
			delay(1);
			err--;
		} 
		if(IRIN==1)			//�����ȷ�ȵ�9ms�͵�ƽ
		{
			err=500;
			while((IRIN==1)&&(err>0))		 //�ȴ�4.5ms����ʼ�ߵ�ƽ��ȥ
			{
				delay(1);
				err--;
			}
			for(k=0;k<4;k++)		//����4������
			{				
				for(j=0;j<8;j++)	//����һ������
				{

					err=60;		
					while((IRIN==0)&&(err>0))//�ȴ��ź�ǰ���560us�͵�ƽ��ȥ
					{
						delay(1);
						err--;
					}
					err=500;
					while((IRIN==1)&&(err>0))	 //����ߵ�ƽ��ʱ�䳤�ȡ�
					{
						delay(10);	 //0.1ms
						Time++;
						err--;
						if(Time>30)
						{
							return;
						}
					}
					IrValue[k]>>=1;	 //k��ʾ�ڼ�������
					if(Time>=8)			//����ߵ�ƽ���ִ���565us����ô��1
					{
						IrValue[k]|=0x80;
					}
					Time=0;		//����ʱ��Ҫ���¸�ֵ							
				}
			}
		}
		if(IrValue[2]!=~IrValue[3])
		{
			return;
		}
	}			
}