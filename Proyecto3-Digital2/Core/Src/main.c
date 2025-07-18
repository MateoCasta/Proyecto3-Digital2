/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define Sensores GPIOB
#define DISPLAY_PORT GPIOB
#define Parqueo1_2 GPIOC
#define Parqueo3_4 GPIOA


/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
uint8_t contador = 8;
uint8_t P1 = 0;
uint8_t P2 = 0;
uint8_t P3 = 0;
uint8_t P4 = 0;
uint8_t ValorI2C = 0x00;
uint8_t ValorCompletoParqueo;
uint8_t paso;






/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_I2C1_Init(void);
/* USER CODE BEGIN PFP */
void SevenSeg_Display(uint8_t numero);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void SevenSeg_Display(uint8_t numero)
{
    // Apagar todos los segmentos
    HAL_GPIO_WritePin(DISPLAY_PORT, A_Pin|B_Pin|C_Pin|D_Pin|E_Pin|F_Pin|G_Pin, GPIO_PIN_RESET);

    switch (numero) {
        case 0:
            HAL_GPIO_WritePin(DISPLAY_PORT, A_Pin|B_Pin|C_Pin|D_Pin|E_Pin|F_Pin, GPIO_PIN_SET);
            break;
        case 1:
            HAL_GPIO_WritePin(DISPLAY_PORT, B_Pin|C_Pin, GPIO_PIN_SET);
            break;
        case 2:
            HAL_GPIO_WritePin(DISPLAY_PORT, A_Pin|B_Pin|D_Pin|E_Pin|G_Pin, GPIO_PIN_SET);
            break;
        case 3:
            HAL_GPIO_WritePin(DISPLAY_PORT, A_Pin|B_Pin|C_Pin|D_Pin|G_Pin, GPIO_PIN_SET);
            break;
        case 4:
            HAL_GPIO_WritePin(DISPLAY_PORT, B_Pin|C_Pin|F_Pin|G_Pin, GPIO_PIN_SET);
            break;
        case 5:
            HAL_GPIO_WritePin(DISPLAY_PORT, A_Pin|C_Pin|D_Pin|F_Pin|G_Pin, GPIO_PIN_SET);
            break;
        case 6:
            HAL_GPIO_WritePin(DISPLAY_PORT, A_Pin|C_Pin|D_Pin|E_Pin|F_Pin|G_Pin, GPIO_PIN_SET);
            break;
        case 7:
            HAL_GPIO_WritePin(DISPLAY_PORT, A_Pin|B_Pin|C_Pin, GPIO_PIN_SET);
            break;
        case 8:
            HAL_GPIO_WritePin(DISPLAY_PORT, A_Pin|B_Pin|C_Pin|D_Pin|E_Pin|F_Pin|G_Pin, GPIO_PIN_SET);
            break;
        case 9:
            HAL_GPIO_WritePin(DISPLAY_PORT, A_Pin|B_Pin|C_Pin|D_Pin|F_Pin|G_Pin, GPIO_PIN_SET);
            break;
        default:
            // apaga todo
            break;
    }
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */








  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  ValorI2C = 0;
	  //Parqueo 1
	  if(HAL_GPIO_ReadPin(Sensores, Sensor1_Pin) == GPIO_PIN_RESET){
		  HAL_GPIO_WritePin(Parqueo1_2, P1V_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(Parqueo1_2, P1R_Pin, GPIO_PIN_SET);
		  P1 = 1;
	  }
	  else if(HAL_GPIO_ReadPin(Sensores, Sensor1_Pin) == GPIO_PIN_SET){
		  HAL_GPIO_WritePin(Parqueo1_2, P1V_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(Parqueo1_2, P1R_Pin, GPIO_PIN_RESET);
		  P1 = 0;
	  }



	  //Parqueo 2
	  if(HAL_GPIO_ReadPin(Sensores, Sensor2_Pin) == GPIO_PIN_RESET){
		  HAL_GPIO_WritePin(Parqueo1_2, P2V_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(Parqueo1_2, P2R_Pin, GPIO_PIN_SET);
		  P2 = 1;


	  }
	  else if(HAL_GPIO_ReadPin(Sensores, Sensor2_Pin) == GPIO_PIN_SET){
		  HAL_GPIO_WritePin(Parqueo1_2, P2V_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(Parqueo1_2, P2R_Pin, GPIO_PIN_RESET);
		  P2 = 0;


	  }


	  //Parqueo 3
	  if(HAL_GPIO_ReadPin(Sensores, Sensor3_Pin) == GPIO_PIN_RESET){
		  HAL_GPIO_WritePin(Parqueo3_4, P3V_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(Parqueo3_4, P3R_Pin, GPIO_PIN_SET);
		  P3 = 1;
	  }
	  else if(HAL_GPIO_ReadPin(Sensores, Sensor3_Pin) == GPIO_PIN_SET){
		  HAL_GPIO_WritePin(Parqueo3_4, P3V_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(Parqueo3_4, P3R_Pin, GPIO_PIN_RESET);
		  P3 = 0;

	  }



	  //Parqueo 4
	  if(HAL_GPIO_ReadPin(Sensores, Sensor4_Pin) == GPIO_PIN_RESET){
		  HAL_GPIO_WritePin(Parqueo3_4, P4V_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(Parqueo3_4, P4R_Pin, GPIO_PIN_SET);
		  P4 = 1;


	  }
	  else  if(HAL_GPIO_ReadPin(Sensores, Sensor4_Pin) == GPIO_PIN_SET){
		  HAL_GPIO_WritePin(Parqueo3_4, P4V_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(Parqueo3_4, P4R_Pin, GPIO_PIN_RESET);
		  P4 = 0;

	  }
	 ValorI2C  |= HAL_GPIO_ReadPin(Sensores, Sensor1_Pin) ? 1<<4 : 0 ;
	 ValorI2C  |= HAL_GPIO_ReadPin(Sensores, Sensor2_Pin) ? 1<<5 : 0 ;
	 ValorI2C  |= HAL_GPIO_ReadPin(Sensores, Sensor3_Pin) ? 1<<6 : 0 ;
	 ValorI2C  |= HAL_GPIO_ReadPin(Sensores, Sensor4_Pin) ? 1<<7 : 0 ;

	 HAL_I2C_Slave_Transmit(&hi2c1, &ValorI2C, 1, HAL_MAX_DELAY);

	 //HAL_I2C_Slave_Receive(&hi2c1, &ValorCompletoParqueo, 1, HAL_MAX_DELAY);


	  HAL_Delay(100);


	  SevenSeg_Display(contador - P1 - P2 - P3 - P4);






    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2|RCC_PERIPHCLK_I2C1;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_HSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x00201D2B;
  hi2c1.Init.OwnAddress1 = 200;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 38400;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LCD_RS_Pin|LD2_Pin|P3R_Pin|P4R_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, A_Pin|B_Pin|C_Pin|D_Pin
                          |E_Pin|F_Pin|G_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, P1V_Pin|P2V_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, P1R_Pin|P2R_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, P3V_Pin|P4V_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LCD_RS_Pin LD2_Pin P3V_Pin P3R_Pin
                           P4V_Pin P4R_Pin */
  GPIO_InitStruct.Pin = LCD_RS_Pin|LD2_Pin|P3V_Pin|P3R_Pin
                          |P4V_Pin|P4R_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : A_Pin B_Pin C_Pin D_Pin
                           E_Pin F_Pin G_Pin */
  GPIO_InitStruct.Pin = A_Pin|B_Pin|C_Pin|D_Pin
                          |E_Pin|F_Pin|G_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : Sensor1_Pin Sensor2_Pin Sensor3_Pin Sensor4_Pin */
  GPIO_InitStruct.Pin = Sensor1_Pin|Sensor2_Pin|Sensor3_Pin|Sensor4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : P1V_Pin P1R_Pin P2V_Pin P2R_Pin */
  GPIO_InitStruct.Pin = P1V_Pin|P1R_Pin|P2V_Pin|P2R_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
