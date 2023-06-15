#include "motor.h"
#include "main.h"
#include "tim.h"
#include "math.h"

void SetMotorSpeed(unsigned char ucChannel,signed char cSpeed)
{
		short sPWM;
	
		if (cSpeed>=100) 
			cSpeed = 100;
	  if (cSpeed<=-100) 
			cSpeed = -100;
	
   	sPWM = 7201 - fabs(cSpeed)*72;
	switch(ucChannel)
	{
		case 0://右轮
			__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_3,sPWM);
			if (cSpeed>0) 

				RIGHT_MOTOR_RESET;
			else if(cSpeed<0) 
				RIGHT_MOTOR_SET;		
			break;
		case 1://左轮
			__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,sPWM);
			if (cSpeed>0) 
				LEFT_MOTOR_SET;
			else if (cSpeed<0)
				LEFT_MOTOR_RESET;
			break;			
	}
}

void forward(signed char speed, int time)//前进
{
	SetMotorSpeed(1,-speed);//左轮  为负数
	SetMotorSpeed(0,speed);//右轮   为正数
	HAL_Delay(time);                 //时间为毫秒
}

void back(signed char speed,int time) //后退
{
	  SetMotorSpeed(1,100-speed);//左轮   //为正数
	  SetMotorSpeed(0,-speed);//右轮 //为负数
		HAL_Delay(time);                 //时间为毫秒  
}

void brake(int time)//刹车
{
	SetMotorSpeed(1,0);//左轮   为0
	SetMotorSpeed(0,0);//右轮   为0
  RIGHT_MOTOR_RESET;
  LEFT_MOTOR_RESET;
	HAL_Delay(time);             //时间为毫秒  
}

void turn_left(signed char speed,int time) //左转弯
{
	  SetMotorSpeed(1,0);//左轮 不动
	  SetMotorSpeed(0,speed);  //右轮为正
		HAL_Delay(time);            //时间为毫秒  
}

void spin_left(signed char speed,int time) //左旋转
{
 	  SetMotorSpeed(1,speed); //左轮    为正
	  SetMotorSpeed(0,100 - speed);     //右轮为正
		HAL_Delay(time);            //时间为毫秒  
}

void turn_right(signed char speed,int time)  //右转弯
{
	  SetMotorSpeed(1,-speed);     //左轮为负
	  SetMotorSpeed(0,0);                 //右轮为0
		HAL_Delay(time);                   //时间为毫秒  
}

void spin_right(signed char speed,int time) //右旋转函数
{
	  SetMotorSpeed(1,-(100-speed));//左轮     //左轮为负
	  SetMotorSpeed(0,-speed);            //右轮为负
		HAL_Delay(time);                    //时间为毫秒  
}
