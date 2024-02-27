#include "stm32f10x.h"

//NVIC
#define $NVIC_PriorityGroup			NVIC_PriorityGroup_2

//LED0 								B5	Unchangeable
#define $LED0_GPIORCC 				RCC_APB2Periph_GPIOB
#define $LED0_GPIOPort				GPIOB
#define $LED0_GPIOPin 				GPIO_Pin_5

//LED1 								E5	Unchangeable
#define $LED1_GPIORCC 				RCC_APB2Periph_GPIOE
#define $LED1_GPIOPort 				GPIOE
#define $LED1_GPIOPin 				GPIO_Pin_5

//Key0 								E4	Unchangeable
#define $Key0_GPIORCC 				RCC_APB2Periph_GPIOE
#define $Key0_GPIOPort 				GPIOE
#define $Key0_GPIOPin	 			GPIO_Pin_4

//KeyUp 							A0	Unchangeable
#define $KeyUp_GPIORCC 				RCC_APB2Periph_GPIOA
#define $KeyUp_GPIOPort 			GPIOA
#define $KeyUp_GPIOPin	 			GPIO_Pin_0

//OLED
#define $OLEDSCL_GPIOPort 			GPIOB
#define $OLEDSCL_GPIOPin 			GPIO_Pin_9
#define $OLEDSDA_GPIOPort 			GPIOB
#define $OLEDSDA_GPIOPin 			GPIO_Pin_9

//Buzzer 							B9
#define $Buzzer_GPIORCC 			RCC_APB2Periph_GPIOB
#define $Buzzer_GPIOPort 			GPIOB
#define $Buzzer_GPIOPin 			GPIO_Pin_9

//LightSensor 						E2
#define $LightSensor_GPIORCC 		RCC_APB2Periph_GPIOE
#define $LightSensor_GPIOPort 		GPIOE
#define $LightSensor_GPIOPin 		GPIO_Pin_2

//CountSensor						E14	EXIT
#define $CountSensor_GPIORCC 		RCC_APB2Periph_GPIOE
#define $CountSensor_GPIOPort 		GPIOE
#define $CountSensor_GPIOPin 		GPIO_Pin_14
#define $CountSensor_AFIOPort		GPIO_PortSourceGPIOE
#define $CountSensor_AFIOPin		GPIO_PinSource14
#define $CountSensor_EXTILine		EXTI_Line14
#define $CountSensor_EXTITrigger	EXTI_Trigger_Falling
#define $CountSensor_EXTIChannel	EXTI15_10_IRQn
#define $CountSensor_EXTIPre		1
#define $CountSensor_EXTISub		1

//Encoder							E0 E1	EXIT
#define $Encoder_GPIORCC 			RCC_APB2Periph_GPIOE
#define $Encoder_GPIOPort 			GPIOE
#define $Encoder_GPIOPin1 			GPIO_Pin_0
#define $Encoder_GPIOPin2			GPIO_Pin_1
#define $Encoder_AFIOPort			GPIO_PortSourceGPIOE
#define $Encoder_AFIOPin1			GPIO_PinSource0
#define $Encoder_AFIOPin2			GPIO_PinSource1
#define $Encoder_EXTILine1			EXTI_Line0
#define $Encoder_EXTILine2			EXTI_Line1
#define $Encoder_EXTITrigger		EXTI_Trigger_Falling
#define $Encoder_EXTIChannel1		EXTI0_IRQn
#define $Encoder_EXTIChannel2		EXTI1_IRQn
#define $Encoder_EXTIPre1			1
#define $Encoder_EXTIPre2			1
#define $Encoder_EXTISub1			1
#define $Encoder_EXTISub2			2

//IntTimer
#define $IntTimer_TIMRCC			RCC_APB1Periph_TIM2
#define $IntTimer_TIM 				TIM2
#define $IntTimer_TIMChannel		TIM2_IRQn
#define $IntTimer_TIMPre			2
#define $IntTimer_TIMSub			1

//ExtTimer
#define $ExtTimer_GPIORCC 			RCC_APB2Periph_GPIOE
#define $ExtTimer_GPIOPort 			GPIOE
#define $ExtTimer_GPIOPin 			GPIO_Pin_14
#define $ExtTimer_TIMRCC 			RCC_APB1Periph_TIM2
#define $ExtTimer_TIM 				TIM2
#define $ExtTimer_TIMChannel		TIM2_IRQn
#define $ExtTimer_TIMPre			2
#define $ExtTimer_TIMSub			1

//PWM								OC1
#define $PWM_TIMRCC					RCC_APB1Periph_TIM2
#define $PWM_TIM 					TIM2
#define $PWM_GPIORCC 				RCC_APB2Periph_GPIOB
#define $PWM_GPIOPort 				GPIOB
#define $PWM_GPIOPin 				GPIO_Pin_9

//Servo								OC2
#define $Servo_TIMRCC				RCC_APB1Periph_TIM2
#define $Servo_TIM 					TIM2
#define $Servo_GPIORCC 				RCC_APB2Periph_GPIOB
#define $Servo_GPIOPort 			GPIOB
#define $Servo_GPIOPin 				GPIO_Pin_9

//Motor								OC3
#define $Motor_TIMRCC				RCC_APB1Periph_TIM2
#define $Motor_TIM 					TIM2
#define $Motor_GPIORCC 				RCC_APB2Periph_GPIOB
#define $Motor_GPIOPort 			GPIOB
#define $Motor_GPIOPin 				GPIO_Pin_9
#define $MotorIN_GPIORCC 			RCC_APB2Periph_GPIOB
#define $MotorIN_GPIOPort 			GPIOB
#define $MotorIN1_GPIOPin 			GPIO_Pin_9
#define $MotorIN2_GPIOPin 			GPIO_Pin_9

//IC								
#define $IC_TIMRCC					RCC_APB1Periph_TIM2
#define $IC_TIM 					TIM2
#define $IC_GPIORCC 				RCC_APB2Periph_GPIOB
#define $IC_GPIOPort 				GPIOB
#define $IC_GPIOPin 				GPIO_Pin_9

//PWMI								
#define $PWMI_TIMRCC				RCC_APB1Periph_TIM2
#define $PWMI_TIM 					TIM2
#define $PWMI_GPIORCC 				RCC_APB2Periph_GPIOB
#define $PWMI_GPIOPort 				GPIOB
#define $PWMI_GPIOPin 				GPIO_Pin_9

//IC								
#define $TIMEncoder_TIMRCC			RCC_APB1Periph_TIM2
#define $TIMEncoder_TIM 			TIM2
#define $TIMEncoder_GPIORCC 		RCC_APB2Periph_GPIOB
#define $TIMEncoder_GPIOPort 		GPIOB
#define $TIMEncoder_GPIOPin1 		GPIO_Pin_9
#define $TIMEncoder_GPIOPin2 		GPIO_Pin_9

//AD
#define $AD_ADCRCC 					RCC_APB2Periph_ADC1
#define $AD_GPIORCC 				RCC_APB2Periph_GPIOA
#define $AD_GPIOPort 				GPIOA
#define $AD_GPIOPin	 				GPIO_Pin_0
#define $AD_ADC						ADC1
#define $AD_ADCChannel				ADC_Channel_0
#define $AD_ADCRank					1
#define $AD_ADCTime					ADC_SampleTime_55Cycles5

//USART
#define $USART_GPIORCC 			RCC_APB2Periph_GPIOA
#define $USART_GPIOPort 			GPIOA
#define $USART_GPIOPin 			GPIO_Pin_9
