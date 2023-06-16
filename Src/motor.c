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
	
		//cSpeed是相对速度百分值，需要换算成相对PWM阈值
		//比如pwm计数0-3599，相对速度50%，需要50%占空比，则阈值应设定为1799
   	sPWM = 3599 - fabs(cSpeed)*36;
	switch(ucChannel)
	{
		case 0://右轮
			/*__HAL_TIM_SetCompare函数控制占空比。
				最后一个参数传入阈值，计数器计数值与这个阈值进行比较
				按照定时计数器的配置得到相应的PWM波*/
			__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_3,sPWM);
			if (cSpeed>0) 
			//控制方向。
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
