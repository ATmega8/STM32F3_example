/**
  ******************************************************************************
  * @file    ADC_Example/stm32f30x_it.c 
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    20-September-2012
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup STM32F3_Discovery_Peripheral_Examples
  * @{
  */

/** @addtogroup ADC_Example
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
__IO uint32_t TimingDelay;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}

/******************************************************************************/
/*                 STM32F30x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f30x.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

#define INMASK (GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2)

uint16_t key_value;
static uint16_t key_flag = 0;
static uint16_t sys_status_new = 0;
static uint16_t sys_status_old = 0;

/*
 * sys_stauts_tab[y][x]
 *                |  |
 * sys_stauts_old--  |
 * key_value----------
 */

static const uint16_t sys_status_tab[4][4]={{1, 0, 0, 0}, 
								   		    {0, 2, 0, 0}, 
								            {0, 0, 0, 3}, 
								            {0, 0, 0, 0}};

void TIM3_IRQHandler(void)
{



	if(TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
		{
				
			while(((uint8_t)(GPIO_ReadInputData(GPIOC)) & 0x07) != 0x07)
			{
				if(key_flag == 0)
				{
					key_flag = 1;
					break;
				}
				else if(key_flag == 1)
				{
					/*key_value: x x x x (LSB)
					 *           | | | |
					 *   PF0------ | | |
					 *   PC2-------- | |
					 *   PC1---------- |
					 *   PC0------------
					 */
					
					key_value = (~GPIO_ReadInputData(GPIOC) & 0x0007);
					//key_value |= ~(GPIO_ReadInputData(GPIOF) & GPIO_Pin_0);
					//key_value &= INMASK | 0x01;

					sys_status_new = sys_status_tab [sys_status_old][key_value - 1];

					switch (sys_status_new)
					{
						case 0:
							break;

						case 1:
							GPIO_WriteBit(GPIOC, GPIO_Pin_13, (BitAction)(1-GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_13)));
							break;

						case 2:
							GPIO_WriteBit(GPIOC, GPIO_Pin_14, (BitAction)(1-GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_14)));
							break;

						case 3:
							GPIO_WriteBit(GPIOC, GPIO_Pin_15, (BitAction)(1-GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_15)));
							break;

						case 4:
							GPIO_WriteBit(GPIOA, GPIO_Pin_1, (BitAction)(1-GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_1)));
							break;

						case 5:
							break;

						case 6:
							break;

						case 7:
							break;

						case 8:
							break;

						case 9:
							break;

						case 10:
							break;

						case 11:
							break;

						case 12:
							break;

						case 13:
							break;

						case 14:
							break;

						case 15:
							break;
					}
				
					key_flag = 0;
					sys_status_old = sys_status_new;
				}

			}

						

			TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
		}
}
/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
