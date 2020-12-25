#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"

 
void Delay( __IO uint32_t nCount )  { 
  while( nCount-- )  { 
  } 
}

 
int main( void )  { 
	//SystemInit();

  /* GPIOG Periph clock enable */ 
  //RCC_AHB1PeriphClockCmd ( RCC_AHB1Periph_GPIOG , ENABLE ) ;

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	asm("nop; nop;");
	GPIOD->MODER = (GPIOD->MODER & ~(GPIO_MODER_MODER12)) | GPIO_MODER_MODER12_0;
	

	/*
  RCC_AHB1PeriphClockCmd ( RCC_AHB1Periph_GPIOD,ENABLE); 
  GPIO_InitTypeDef GPIO_InitStructure ;
  GPIO_InitStructure. GPIO_Pin  =  GPIO_Pin_12; 
  GPIO_InitStructure. GPIO_Mode  = GPIO_Mode_OUT ; 
  GPIO_InitStructure. GPIO_OType  = GPIO_OType_PP ; 
  GPIO_InitStructure. GPIO_Speed  = GPIO_Speed_100MHz ; 
  GPIO_InitStructure. GPIO_PuPd  = GPIO_PuPd_NOPULL ; 
  GPIO_Init ( GPIOD ,  & GPIO_InitStructure ) ;
	*/

	/*
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd ( RCC_AHB1Periph_GPIOD,ENABLE); 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz; 
	GPIO_Init(GPIOD, &GPIO_InitStructure);	
	GPIO_SetBits(GPIOD,GPIO_Pin_12);
	*/

  while  ( 1 )  { 
    GPIOD -> BSRRL = 1<<12; 
    Delay ( 700000L ) ;
	
 
    GPIOD -> BSRRH = 1<<12; 
    Delay ( 700000L ) ;
 

  } 
}
