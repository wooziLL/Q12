#include "rtthread.h"
#include "main.h"
#include "stdio.h"
#include "usart.h"
struct rt_thread led_thread;
rt_uint8_t rt_led_thread_stack[128];
void led_task_entry(void *parameter);
 
//��ʼ���̺߳���
void MX_RT_Thread_Init(void)
{
	//��ʼ��LED�߳�
	rt_thread_init(&led_thread,"led",led_task_entry,RT_NULL,&rt_led_thread_stack[0],sizeof(rt_led_thread_stack),3,20);
	//�����̵߳���
	rt_thread_startup(&led_thread);
	
}
 
//������
void MX_RT_Thread_Process(void)
{
	printf("Hello RT_Thread!!!");
	rt_thread_delay(2000);
}
 
//LED����
void led_task_entry(void *parameter)
{
	while(1)
	{
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_15, GPIO_PIN_RESET);
		rt_thread_delay(500);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_15, GPIO_PIN_SET);
		rt_thread_delay(500);
	}
}

