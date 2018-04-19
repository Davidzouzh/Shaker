//******************************************************************************/	 
//  �� �� ��   : oled.c
//  �� �� ��   : v1.0
//  ��    ��   : zouzhihua
//  ��������   : 2017/04/22
//  ����޸�   : 
//  ��������   : OLED 7��Ӳ��SPI�ӿ���ʾ����(STM32)
//              ˵��:
//				SSD1306 OLED ����IC��������
//				������ʽ:3��SPI
//              ----------------------------------------------------------------
//              GND  ��Դ��


#include "oled.h"
#include "spi.h"
#include "timer.h"
#include "stdlib.h"
#include "math.h" 

#include "oledfont.h"
#include "oledChinese.h"

#define XLevelL		0x00
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xEF
#define X_WIDTH 	128
#define Y_WIDTH 	7
//-----------------OLED�˿ڶ���----------------  					   
#define OLED_RST_Clr() GPIO_ResetBits(GPIOA,GPIO_Pin_2)//RES
#define OLED_RST_Set() GPIO_SetBits(GPIOA,GPIO_Pin_2)

#define OLED_DC_Clr() GPIO_ResetBits(GPIOA,GPIO_Pin_3)//DC
#define OLED_DC_Set() GPIO_SetBits(GPIOA,GPIO_Pin_3)

#define OLED_CS_Clr()  GPIO_ResetBits(GPIOA,GPIO_Pin_4)//CS
#define OLED_CS_Set()  GPIO_SetBits(GPIOA,GPIO_Pin_4)

#define OLED_CMD  0	//д����
#define OLED_DATA 1	//д����

//OLED���Դ�
//��Ÿ�ʽ����.
//[0]0 1 2 3 ... 127	
//[1]0 1 2 3 ... 127	
//[2]0 1 2 3 ... 127	
//[3]0 1 2 3 ... 127	
//[4]0 1 2 3 ... 127	
//[5]0 1 2 3 ... 127	
//[6]0 1 2 3 ... 127	
//[7]0 1 2 3 ... 127 			   

//��SSD1306д��һ���ֽڡ�
//dat:Ҫд�������/����
//cmd:����/�����־ 0,��ʾ����;1,��ʾ����;
void OLED_WR_Byte(u8 dat,u8 cmd)
{				  
	if(cmd)
	  OLED_DC_Set();
	else 
	  OLED_DC_Clr();
	OLED_CS_Clr();  
	SPI1_ReadWriteByte(dat);
	OLED_CS_Set();
	OLED_DC_Set();   	  
} 
void OLED_WR_Byte2(u8 dat,u8 cmd)
{				  
	if(cmd)
	  OLED_DC_Set();
	else 
	  OLED_DC_Clr();
	OLED_CS_Clr();
	SPI1_ReadWriteByte(dat);
	OLED_CS_Set();	
	OLED_DC_Set();   	  
}
   	  
//����OLED��ʾ    
void OLED_Display_On(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC����
	OLED_WR_Byte(0X14,OLED_CMD);  //DCDC ON
	OLED_WR_Byte(0XAF,OLED_CMD);  //DISPLAY ON
}
//�ر�OLED��ʾ     
void OLED_Display_Off(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC����
	OLED_WR_Byte(0X10,OLED_CMD);  //DCDC OFF
	OLED_WR_Byte(0XAE,OLED_CMD);  //DISPLAY OFF
}		   			 
//��������,������,������Ļ�Ǻ�ɫ��!��û����һ��!!!	  
void OLED_Clear(void)  
{  
	u8 i,n;		    
	for(i=0;i<8;i++)  
	{  
		OLED_WR_Byte (0xb0+i,OLED_CMD);    //����ҳ��ַ��0~7��
		OLED_WR_Byte (XLevelL,OLED_CMD);      //������ʾλ�á��е͵�ַ
		OLED_WR_Byte (XLevelH,OLED_CMD);      //������ʾλ�á��иߵ�ַ   
		for(n=0;n<128;n++)OLED_WR_Byte(0,OLED_DATA); 
	}
}


//��ָ��λ��д���ֽڣ���ʼ������(x,y),x�ķ�Χ0��127��yΪҳ�ķ�Χ0��7
void OLED_Set_Pos(unsigned char x, unsigned char y) 
{ 
	OLED_WR_Byte(0xb0+y,OLED_CMD);
	OLED_WR_Byte(((x&0xf0)>>4)|0x10,OLED_CMD);
	OLED_WR_Byte((x&0x0f)|0x01,OLED_CMD); 
}

//��ָ��λ����ʾһ���ַ�,���������ַ�
//x:0~127
//y:0~7
//mode1:������ʾ				 
//size:ѡ������ 16/12 
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size)
{      	
	unsigned char c,i;
	if((chr<='~')&&(chr>=' '))//�ж��ǲ��ǷǷ��ַ�!
	{
		c=chr-' ';//�õ�ƫ�ƺ��ֵ			
		if(x>Max_Column-1){x=0;y=y+2;}
		if(size == 16)
		{
			OLED_Set_Pos(x,y);	
			for(i=0;i<8;i++)
				OLED_WR_Byte(asc2_1608[c][i],OLED_DATA);
			OLED_Set_Pos(x,y+1);
			for(i=0;i<8;i++)
				OLED_WR_Byte(asc2_1608[c][i+8],OLED_DATA);
		}
		else {	
			OLED_Set_Pos(x,y);	
			for(i=0;i<12;i++)
				OLED_WR_Byte(asc2_2412[c*3][i],OLED_DATA);
			OLED_Set_Pos(x,y+1);
			for(i=0;i<12;i++)
				OLED_WR_Byte(asc2_2412[c*3+1][i],OLED_DATA);
			OLED_Set_Pos(x,y+2);
			for(i=0;i<12;i++)
				OLED_WR_Byte(asc2_2412[c*3+2][i],OLED_DATA);
		}
	}	
	
}
//m^n����
u32 oled_pow(u8 m,u8 n)
{
	u32 result=1;	 
	while(n--)result*=m;    
	return result;
}				  
//��ʾlen������
//x,y :�������	 
//len :���ֵ�λ��
//size:�����С
//mode1:������ʾ
//num:��ֵ(0~4294967295);	 		
 
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size)
{         	
	u8 t,temp;
	u8 enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/oled_pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				OLED_ShowChar(x+(size/2)*t,y,' ',size);
				continue;
			}else enshow=1; 
		 	 
		}
	 	OLED_ShowChar(x+(size/2)*t,y,temp+'0',size); 
	}
}

void OLED_Show1Numwith1Dot(u8 x,u8 y,float num,u8 size)
{
	float second;
	second = num-floor(num);//С������
	
	if(size == 16)
	{
		OLED_ShowNum(x,y,num,1,16);
		OLED_ShowChar(x,y+8,'.',16);
		OLED_ShowNum(x,y+16,second,1,16);
	}
	else
	{
		OLED_ShowNum(x,y,num,1,24);
		OLED_ShowChar(x,y+12,'.',24);
		OLED_ShowNum(x,y+24,second,1,24);
	}
	
	
}

//��ʾһ���ַ��Ŵ�
//x:0~127
//y:0~7
//mode1:������ʾ				 
//size:ѡ������ 16/12 
void OLED_ShowString(u8 x,u8 y,u8 *chr,u8 size)
{
	unsigned char j=0;
	while(chr[j]!='\0')
	{
		OLED_ShowChar(x,y,chr[j],size);
		if(size == 16)
		{
			x+=8;
			if(x>120){x=0;y+=2;}
		}			
		else{
			x+=12;
			if(x>122){x=0;y+=2;}
		}
		j++;
	}
}
//��ʾ����
//x:0~127
//y:0~7				 
//size:16*16 
void OLED_ShowCHinese(u8 x,u8 y,u8 num,u8 size)
{      			    
	u8 t;
	OLED_Set_Pos(x,y);	
    if(size == 16)
	{
		for(t=0;t<16;t++)
			OLED_WR_Byte(Hzk_16[2*num][t],OLED_DATA);	
		OLED_Set_Pos(x,y+1);	
		for(t=0;t<16;t++)
			OLED_WR_Byte(Hzk_16[2*num+1][t],OLED_DATA);	
	}
	else{
		for(t=0;t<24;t++)
			OLED_WR_Byte2(Hzk_24[3*num][t],OLED_DATA);	
		OLED_Set_Pos(x,y+1);	
		for(t=0;t<24;t++)
			OLED_WR_Byte2(Hzk_24[3*num+1][t],OLED_DATA);
		OLED_Set_Pos(x,y+2);	
		for(t=0;t<24;t++)
			OLED_WR_Byte2(Hzk_24[3*num+2][t],OLED_DATA);		
	}
}
//��ʾBMPͼƬ128��64
//��ʼ������(x,y),x�ķ�Χ0��127��yΪҳ�ķ�Χ0��7
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[])
{ 	
	unsigned int j=0;
	unsigned char x,y;
	for(y=y0;y<y1;y++)
	{
		OLED_Set_Pos(x0,y);
		for(x=x0;x<x1;x++)      
			OLED_WR_Byte(BMP[j++],OLED_DATA);
	}
} 


//��ʼ��SSD1306					    
void OLED_Init(void)
{
 	GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //ʹ��A�˿�ʱ��

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 |GPIO_Pin_3|GPIO_Pin_4;	 
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//�ٶ�50MHz
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
 	GPIO_SetBits(GPIOA, GPIO_Pin_2 |GPIO_Pin_3|GPIO_Pin_4);
//��ʼ��A8,A9,A10
	
	SPI1_Init();


	OLED_RST_Set();
	delay_ms(100);
	OLED_RST_Clr();
	delay_ms(200);
	OLED_RST_Set(); 

	
	OLED_WR_Byte(0xAE,OLED_CMD); //�ر���ʾ
	
	OLED_WR_Byte(0x81,OLED_CMD); //�Աȶ�����
	OLED_WR_Byte(Brightness,OLED_CMD); //1~255;Ĭ��0X7F (��������,Խ��Խ��)

	OLED_WR_Byte(XLevelL,OLED_CMD); //������ʾλ�á��е͵�ַ
	OLED_WR_Byte(XLevelH,OLED_CMD); //������ʾλ�á��иߵ�ַ
	OLED_WR_Byte(0x20,OLED_CMD); //�����ڴ��ַģʽ
	OLED_WR_Byte(0x02,OLED_CMD); //[1:0],00���е�ַģʽ;01���е�ַģʽ;10,ҳ��ַģʽ;Ĭ��10;

	OLED_WR_Byte(0xD3,OLED_CMD); //������ʾƫ��
	OLED_WR_Byte(0X00,OLED_CMD); //Ĭ��Ϊ0
	OLED_WR_Byte(0x40,OLED_CMD); //������ʾ��ʼ�� [5:0],����.
	
	OLED_WR_Byte(0xA1,OLED_CMD); //���ض�������,bit0:0,127->0,���ҷ���;1,0->127,����;
	OLED_WR_Byte(0xC8,OLED_CMD); //����COMɨ�跽��;bit3:0,��ͨģʽ������;1,�ض���ģʽ COM[N-1]->COM0;N:����·�������·���
	OLED_WR_Byte(0xA8,OLED_CMD); //��������·��
	OLED_WR_Byte(0X3F,OLED_CMD); //Ĭ��0X3F(1/64) 
	OLED_WR_Byte(0xDA,OLED_CMD); //����COMӲ����������
	OLED_WR_Byte(0x12,OLED_CMD); //[5:4]����
		 
	OLED_WR_Byte(0xD9,OLED_CMD); //����Ԥ�������
	OLED_WR_Byte(0xf1,OLED_CMD); //[3:0],PHASE 1;[7:4],PHASE 2;
	OLED_WR_Byte(0xDB,OLED_CMD); //����VCOMH ��ѹ����
	OLED_WR_Byte(0x30,OLED_CMD); //[6:4] 000,0.65*vcc;001,0.77*vcc;011,0.83*vcc;
	
	OLED_WR_Byte(0xA4,OLED_CMD); //ȫ����ʾ����;bit0:1,����;0,�ر�;(����/����)
	OLED_WR_Byte(0xA6,OLED_CMD); //������ʾ��ʽ;bit0:1,������ʾ;0,������ʾ

	OLED_WR_Byte(0xD5,OLED_CMD); //����ʱ�ӷ�Ƶ����,��Ƶ��
	OLED_WR_Byte(0x80,OLED_CMD); //[3:0],��Ƶ����;[7:4],��Ƶ��
	OLED_WR_Byte(0x8D,OLED_CMD); //��ɱ�����
	OLED_WR_Byte(0x14,OLED_CMD); //bit2������/�ر�
	
	OLED_WR_Byte(0xAF,OLED_CMD); //������ʾ
	
	
	OLED_Clear();
	OLED_Set_Pos(0,0); 	
}  
