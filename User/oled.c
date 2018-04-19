//******************************************************************************/	 
//  文 件 名   : oled.c
//  版 本 号   : v1.0
//  作    者   : zouzhihua
//  生成日期   : 2017/04/22
//  最近修改   : 
//  功能描述   : OLED 7针硬件SPI接口演示例程(STM32)
//              说明:
//				SSD1306 OLED 驱动IC驱动代码
//				驱动方式:3线SPI
//              ----------------------------------------------------------------
//              GND  电源地


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
//-----------------OLED端口定义----------------  					   
#define OLED_RST_Clr() GPIO_ResetBits(GPIOA,GPIO_Pin_2)//RES
#define OLED_RST_Set() GPIO_SetBits(GPIOA,GPIO_Pin_2)

#define OLED_DC_Clr() GPIO_ResetBits(GPIOA,GPIO_Pin_3)//DC
#define OLED_DC_Set() GPIO_SetBits(GPIOA,GPIO_Pin_3)

#define OLED_CS_Clr()  GPIO_ResetBits(GPIOA,GPIO_Pin_4)//CS
#define OLED_CS_Set()  GPIO_SetBits(GPIOA,GPIO_Pin_4)

#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据

//OLED的显存
//存放格式如下.
//[0]0 1 2 3 ... 127	
//[1]0 1 2 3 ... 127	
//[2]0 1 2 3 ... 127	
//[3]0 1 2 3 ... 127	
//[4]0 1 2 3 ... 127	
//[5]0 1 2 3 ... 127	
//[6]0 1 2 3 ... 127	
//[7]0 1 2 3 ... 127 			   

//向SSD1306写入一个字节。
//dat:要写入的数据/命令
//cmd:数据/命令标志 0,表示命令;1,表示数据;
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
   	  
//开启OLED显示    
void OLED_Display_On(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC命令
	OLED_WR_Byte(0X14,OLED_CMD);  //DCDC ON
	OLED_WR_Byte(0XAF,OLED_CMD);  //DISPLAY ON
}
//关闭OLED显示     
void OLED_Display_Off(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC命令
	OLED_WR_Byte(0X10,OLED_CMD);  //DCDC OFF
	OLED_WR_Byte(0XAE,OLED_CMD);  //DISPLAY OFF
}		   			 
//清屏函数,清完屏,整个屏幕是黑色的!和没点亮一样!!!	  
void OLED_Clear(void)  
{  
	u8 i,n;		    
	for(i=0;i<8;i++)  
	{  
		OLED_WR_Byte (0xb0+i,OLED_CMD);    //设置页地址（0~7）
		OLED_WR_Byte (XLevelL,OLED_CMD);      //设置显示位置—列低地址
		OLED_WR_Byte (XLevelH,OLED_CMD);      //设置显示位置—列高地址   
		for(n=0;n<128;n++)OLED_WR_Byte(0,OLED_DATA); 
	}
}


//在指定位置写入字节，起始点坐标(x,y),x的范围0～127，y为页的范围0～7
void OLED_Set_Pos(unsigned char x, unsigned char y) 
{ 
	OLED_WR_Byte(0xb0+y,OLED_CMD);
	OLED_WR_Byte(((x&0xf0)>>4)|0x10,OLED_CMD);
	OLED_WR_Byte((x&0x0f)|0x01,OLED_CMD); 
}

//在指定位置显示一个字符,包括部分字符
//x:0~127
//y:0~7
//mode1:正常显示				 
//size:选择字体 16/12 
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size)
{      	
	unsigned char c,i;
	if((chr<='~')&&(chr>=' '))//判断是不是非法字符!
	{
		c=chr-' ';//得到偏移后的值			
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
//m^n函数
u32 oled_pow(u8 m,u8 n)
{
	u32 result=1;	 
	while(n--)result*=m;    
	return result;
}				  
//显示len个数字
//x,y :起点坐标	 
//len :数字的位数
//size:字体大小
//mode1:正常显示
//num:数值(0~4294967295);	 		
 
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
	second = num-floor(num);//小数部分
	
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

//显示一个字符号串
//x:0~127
//y:0~7
//mode1:正常显示				 
//size:选择字体 16/12 
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
//显示汉字
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
//显示BMP图片128×64
//起始点坐标(x,y),x的范围0～127，y为页的范围0～7
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


//初始化SSD1306					    
void OLED_Init(void)
{
 	GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //使能A端口时钟

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 |GPIO_Pin_3|GPIO_Pin_4;	 
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//速度50MHz
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
 	GPIO_SetBits(GPIOA, GPIO_Pin_2 |GPIO_Pin_3|GPIO_Pin_4);
//初始化A8,A9,A10
	
	SPI1_Init();


	OLED_RST_Set();
	delay_ms(100);
	OLED_RST_Clr();
	delay_ms(200);
	OLED_RST_Set(); 

	
	OLED_WR_Byte(0xAE,OLED_CMD); //关闭显示
	
	OLED_WR_Byte(0x81,OLED_CMD); //对比度设置
	OLED_WR_Byte(Brightness,OLED_CMD); //1~255;默认0X7F (亮度设置,越大越亮)

	OLED_WR_Byte(XLevelL,OLED_CMD); //设置显示位置—列低地址
	OLED_WR_Byte(XLevelH,OLED_CMD); //设置显示位置—列高地址
	OLED_WR_Byte(0x20,OLED_CMD); //设置内存地址模式
	OLED_WR_Byte(0x02,OLED_CMD); //[1:0],00，列地址模式;01，行地址模式;10,页地址模式;默认10;

	OLED_WR_Byte(0xD3,OLED_CMD); //设置显示偏移
	OLED_WR_Byte(0X00,OLED_CMD); //默认为0
	OLED_WR_Byte(0x40,OLED_CMD); //设置显示开始行 [5:0],行数.
	
	OLED_WR_Byte(0xA1,OLED_CMD); //段重定义设置,bit0:0,127->0,左右反置;1,0->127,正常;
	OLED_WR_Byte(0xC8,OLED_CMD); //设置COM扫描方向;bit3:0,普通模式，正常;1,重定义模式 COM[N-1]->COM0;N:驱动路数，上下反置
	OLED_WR_Byte(0xA8,OLED_CMD); //设置驱动路数
	OLED_WR_Byte(0X3F,OLED_CMD); //默认0X3F(1/64) 
	OLED_WR_Byte(0xDA,OLED_CMD); //设置COM硬件引脚配置
	OLED_WR_Byte(0x12,OLED_CMD); //[5:4]配置
		 
	OLED_WR_Byte(0xD9,OLED_CMD); //设置预充电周期
	OLED_WR_Byte(0xf1,OLED_CMD); //[3:0],PHASE 1;[7:4],PHASE 2;
	OLED_WR_Byte(0xDB,OLED_CMD); //设置VCOMH 电压倍率
	OLED_WR_Byte(0x30,OLED_CMD); //[6:4] 000,0.65*vcc;001,0.77*vcc;011,0.83*vcc;
	
	OLED_WR_Byte(0xA4,OLED_CMD); //全局显示开启;bit0:1,开启;0,关闭;(白屏/黑屏)
	OLED_WR_Byte(0xA6,OLED_CMD); //设置显示方式;bit0:1,反相显示;0,正常显示

	OLED_WR_Byte(0xD5,OLED_CMD); //设置时钟分频因子,震荡频率
	OLED_WR_Byte(0x80,OLED_CMD); //[3:0],分频因子;[7:4],震荡频率
	OLED_WR_Byte(0x8D,OLED_CMD); //电荷泵设置
	OLED_WR_Byte(0x14,OLED_CMD); //bit2，开启/关闭
	
	OLED_WR_Byte(0xAF,OLED_CMD); //开启显示
	
	
	OLED_Clear();
	OLED_Set_Pos(0,0); 	
}  
