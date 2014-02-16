/**
  ******************************************************************************
  * @file    ADC_Example/main.h 
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    20-September-2012
  * @brief   Header for main.c module
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f30x.h"
#include "stm32f30x_conf.h"
#include "stm32f30x_it.h"
//#include "1602.h"
#include "tim.h"
//#include "nvic.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void Delay(__IO uint32_t nTime);
#endif /* __MAIN_H */
static const uint16_t SRC_Buffer[100]={
3301,
3401,
3501,
3601,
3701,
3800,
3898,
3996,
4093,
4189,
4284,
4378,
4471,
4563,
4653,
4742,
4829,
4915,
4999,
5081,
5161,
5240,
5316,
5391,
5463,
5533,
5600,
5666,
5729,
5789,
5847,
5902,
5954,
6004,
6051,
6095,
6137,
6175,
6211,
6243,
6273,
6299,
6323,
6343,
6361,
6375,
6386,
6394,
6398,
6400,
6398,
6394,
6386,
6375,
6361,
6343,
6323,
6299,
6273,
6243,
6211,
6175,
6137,
6095,
6051,
6004,
5954,
5902,
5847,
5789,
5728,
5665,
5600,
5533,
5463,
5390,
5316,
5240,
5161,
5081,
4998,
4914,
4829,
4741,
4653,
4562,
4471,
4378,
4284,
4189,
4092,
3996,
3898,
3799,
3700,
3601,
3501,
3401,
3300,
3200};
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
