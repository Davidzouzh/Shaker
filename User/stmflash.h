

#ifndef STMFLASH__
#define STMFLASH__

#include "stm32f10x.h"  


//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103C8T6--->64K Bytes  flash
//С����STM32�����һҳ��ʼ��ַΪ0x0800FC00��������ַΪ0x0800FFFF
//ÿһҳ��СΪ1K���ֽ�
//////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//�û������Լ�����Ҫ����
#define STM32_FLASH_SIZE	64				//��ѡSTM32��FLASH������С(��λΪK)
#define STM32_FLASH_WREN	1				//ʹ��FLASHд��(0��������;1��ʹ��)
//////////////////////////////////////////////////////////////////////////////////////////////////////

//FLASH��ʼ��ַ
#define STM32_FLASH_BASE		0x08000000 	//STM32 FLASH����ʼ��ַ
#define STM32_FLASH_OFFEST		0x0000FC00 	//��Ϊ����Flash�����ʼ��ַ��ƫ������ʹ��FLASH�����һҳ
 


 
u16 STMFLASH_ReadHalfWord(u32 faddr);		  //��������  
void STMFLASH_WriteLenByte(u32 WriteAddr,u32 DataToWrite,u16 Len);	//ָ����ַ��ʼд��ָ�����ȵ�����
u32 STMFLASH_ReadLenByte(u32 ReadAddr,u16 Len);						//ָ����ַ��ʼ��ȡָ����������
void STMFLASH_Write(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite);		//��ָ����ַ��ʼд��ָ�����ȵ�����
void STMFLASH_Read(u32 ReadAddr,u16 *pBuffer,u16 NumToRead);   		//��ָ����ַ��ʼ����ָ�����ȵ�����

//����д��
void Test_Write(u32 WriteAddr,u16 WriteData);								   
#endif


