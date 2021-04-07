#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <ctype.h>  //isdigit����
#include "Calculator.h"
#define SIZE 1000
extern Elem InfixExpression[SIZE]; //��׺���ʽ
extern Elem PostfixExpression[SIZE];//��׺���ʽ
LinkStack StackNum;





//��׺���ʽ�������  ʹ���˺�׺���ʽ���飨���ޣ��� �� �Լ�������ջ  �������ǡ�ɲ��ܴ�����
double Calculate()
{
	
	double result=0;//Pop����Ԫ��

	
	//���
	printf("||-->��׺���ʽΪ��");
	for (size_t i = 0; i < SIZE; ++i)
	{
		if (!PostfixExpression[i].IsNum && PostfixExpression[i].oper == '=')
		{
			printf("%c\n", '=');
			break;
		}
		else if (PostfixExpression[i].IsNum)
		{
			printf(" %d ", PostfixExpression[i].num);
		}
		else
		{
			printf("%c", PostfixExpression[i].oper);
		}
	}

	
	
	StackNum.top = NULL;
	initLStack(&StackNum);

	//����
	for (size_t i = 0; i < SIZE; ++i)
	{
		
		
		if (PostfixExpression[i].oper == '=')
		{
			Pop(&StackNum, &result);
			return result; //ȡ�������
		}
		//������ջ 
		else if (PostfixExpression[i].IsNum)
		{

			Push(&StackNum, (double)(PostfixExpression[i].num));
		}
		
		//�������� Pop��ջ����Ԫ�ؽ��м��㲢���������ѹ��ջ
		else
		{


			//temp�����ݴ�ջ����Ԫ�صļ�����
			double temp = 0.0;
			//ע�⣬��һ��Pop�Ҳ��������ڶ���PopN�������
			double rear;
			Pop(&StackNum, &result);
			rear = result;


			double front ;
			Pop(&StackNum, &result);
			front = result;


			//���ݵ�ǰԪ��ѡ��Ӧ���е����㣬���������ջ
			switch (PostfixExpression[i].oper)
			{
			case '+':
				temp = front + rear;
				Push(&StackNum, temp);
				break;
			case '-':
				temp = front - rear;
				Push(&StackNum, temp);
				break;
			case '*':
				temp = front * rear;
				Push(&StackNum, temp);
				break;
			case '/':
				temp = front / rear;
				Push(&StackNum, temp);
				break;
			}
		}
	}

	return 0;
}


Status InitLStack(LinkStack* s) {

	LinkStackPtr stack = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!stack)
	{
		return ERROR;
	}
	else {
		s->count = 0;
		s->top = stack;
		//stack->data = 0;ͷָ�벻��Ԫ��
		s->top->next = NULL; //Ϊ��һ���ڵ�ָ�����׼��
	}


	return SUCCESS;
}
Status Push(LinkStack* s, ElemType data)
//����ͷ�ڵ����ϱ�  һֱ�ı�
{
	

	LinkStackPtr newst = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!newst)
	{
		return ERROR;
	}
	else {
		newst->data = data;

		newst->next = s->top->next;
		s->top->next = newst;//ͷָ��ָ��ͷ��� һֱ�ı�
		s->count++;
		return SUCCESS;
	}

}

Status Pop(LinkStack* s, ElemType* data)
{
	
	if (!IsEmpty(s))
	{
		LinkStackPtr tmpst = (LinkStackPtr)malloc(sizeof(StackNode));
		tmpst = s->top->next;
		*data = tmpst->data;
		s->top->next = tmpst->next;
		free(tmpst);
		s->count--;
		return SUCCESS;
	}
	else {
		printf("||-->ջ��!\n");
	}
	return 0;
}

//���ջ
Status Clear(LinkStack* s)
{
	double data;
	
	printf("||-->ջ��Ԫ�أ�\n");

	while (!IsEmpty(s))
	{
		Pop(s, &data);
		printf("%d ", data);
	}
	printf("\n");
}

//����ջ
Status Destroy(LinkStack* s)
{
	double data;
	
	printf("||-->ջ��Ԫ��:");

	while (!IsEmpty(s))
	{
		Pop(s, &data);
		printf("%d ", data);
	}
	printf("\n");
	s->top = NULL;
	return SUCCESS;
}

Status IsEmpty(LinkStack* s)
{


	if (s->top->next == NULL)
	{
		return SUCCESS;
	}
	else {

		return ERROR;
	}
}




