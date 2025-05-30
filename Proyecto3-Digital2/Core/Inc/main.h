/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LCD_RS_Pin GPIO_PIN_4
#define LCD_RS_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define A_Pin GPIO_PIN_0
#define A_GPIO_Port GPIOB
#define B_Pin GPIO_PIN_1
#define B_GPIO_Port GPIOB
#define C_Pin GPIO_PIN_2
#define C_GPIO_Port GPIOB
#define Sensor1_Pin GPIO_PIN_12
#define Sensor1_GPIO_Port GPIOB
#define Sensor2_Pin GPIO_PIN_13
#define Sensor2_GPIO_Port GPIOB
#define Sensor3_Pin GPIO_PIN_14
#define Sensor3_GPIO_Port GPIOB
#define Sensor4_Pin GPIO_PIN_15
#define Sensor4_GPIO_Port GPIOB
#define P1V_Pin GPIO_PIN_6
#define P1V_GPIO_Port GPIOC
#define P1R_Pin GPIO_PIN_7
#define P1R_GPIO_Port GPIOC
#define P2V_Pin GPIO_PIN_8
#define P2V_GPIO_Port GPIOC
#define P2R_Pin GPIO_PIN_9
#define P2R_GPIO_Port GPIOC
#define P3V_Pin GPIO_PIN_8
#define P3V_GPIO_Port GPIOA
#define P3R_Pin GPIO_PIN_9
#define P3R_GPIO_Port GPIOA
#define P4V_Pin GPIO_PIN_10
#define P4V_GPIO_Port GPIOA
#define P4R_Pin GPIO_PIN_11
#define P4R_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define D_Pin GPIO_PIN_3
#define D_GPIO_Port GPIOB
#define E_Pin GPIO_PIN_4
#define E_GPIO_Port GPIOB
#define F_Pin GPIO_PIN_5
#define F_GPIO_Port GPIOB
#define G_Pin GPIO_PIN_6
#define G_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
