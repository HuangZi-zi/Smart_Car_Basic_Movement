#ifndef __MOTOR_H_
#define __MOTOR_H_

#include "main.h"

//函数声明
void SetMotorSpeed(unsigned char ucChannel,signed char cSpeed);
void forward(signed char speed, int time);
void back(signed char speed,int time);
void brake(int time);
void turn_left(signed char speed,int time);
void spin_left(signed char speed,int time);
void turn_right(signed char speed,int time);
void spin_right(signed char speed,int time);

//IO接口定义
// 左电机 方向：PB7 PWM: PB8
// 右电机 方向：PA4 PWM: PB9
#define LEFT_MOTOR_PIN							GPIO_PIN_7
#define LEFT_MOTOR_GPIO							GPIOB
#define LEFT_MOTOR_SET							HAL_GPIO_WritePin(LEFT_MOTOR_GPIO,LEFT_MOTOR_PIN,GPIO_PIN_SET)
#define LEFT_MOTOR_RESET						HAL_GPIO_WritePin(LEFT_MOTOR_GPIO,LEFT_MOTOR_PIN,GPIO_PIN_RESET)

#define LEFT_MOTOR_PWM_PIN					GPIO_PIN_8
#define LEFT_MOTOR_PWM_GPIO					GPIOB
#define LEFT_MOTOR_PWM_SET					HAL_GPIO_WritePin(LEFT_MOTOR_PWM_GPIO,LETF_MOTOR_PWM_PIN,GPIO_PIN_SET)
#define LEFT_MOTOR_PWM_RESET				HAL_GPIO_WritePin(LEFT_MOTOR_PWM_GPIO,LETF_MOTOR_PWM_PIN,GPIO_PIN_RESET)

#define RIGHT_MOTOR_PIN							GPIO_PIN_4
#define RIGHT_MOTOR_GPIO						GPIOA
#define RIGHT_MOTOR_SET							HAL_GPIO_WritePin(RIGHT_MOTOR_GPIO,RIGHT_MOTOR_PIN,GPIO_PIN_SET)
#define RIGHT_MOTOR_RESET						HAL_GPIO_WritePin(RIGHT_MOTOR_GPIO,RIGHT_MOTOR_PIN,GPIO_PIN_RESET)

#define RIGHT_MOTOR_PWM_PIN					GPIO_PIN_9
#define RIGHT_MOTOR_PWM_GPIO				GPIOB
#define RIGHT_MOTOR_PWM_SET					HAL_GPIO_WritePin(RIGHT_MOTOR_PWM_GPIO,RIGHT_MOTOR_PWM_PIN,GPIO_PIN_SET)
#define RIGHT_MOTOR_PWM_RESET				HAL_GPIO_WritePin(RIGHT_MOTOR_PWM_GPIO,RIGHT_MOTOR_PWM_PIN,GPIO_PIN_RESET)
#endif
