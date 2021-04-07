#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <ctype.h>  //isdigit函数
#include "Calculator.h"
#define SIZE 1000
extern Elem InfixExpression[SIZE]; //中缀表达式
extern Elem PostfixExpression[SIZE];//后缀表达式
LinkStack StackNum;





//后缀表达式计算规则  使用了后缀表达式数组（内无（） ） 以及操作数栈  而计算机恰巧不能处理（）
double Calculate()
{
	
	double result=0;//Pop出的元素

	
	//检查
	printf("||-->后缀表达式为：");
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

	//计算
	for (size_t i = 0; i < SIZE; ++i)
	{
		
		
		if (PostfixExpression[i].oper == '=')
		{
			Pop(&StackNum, &result);
			return result; //取出最后结果
		}
		//数字入栈 
		else if (PostfixExpression[i].IsNum)
		{

			Push(&StackNum, (double)(PostfixExpression[i].num));
		}
		
		//遇到符号 Pop出栈顶两元素进行计算并将结果重新压入栈
		else
		{


			//temp用于暂存栈顶两元素的计算结果
			double temp = 0.0;
			//注意，第一次Pop右操作数，第二次PopN左操作数
			double rear;
			Pop(&StackNum, &result);
			rear = result;


			double front ;
			Pop(&StackNum, &result);
			front = result;


			//根据当前元素选择应进行的运算，并将结果入栈
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
		//stack->data = 0;头指针不存元素
		s->top->next = NULL; //为第一个节点指向空做准备
	}


	return SUCCESS;
}
Status Push(LinkStack* s, ElemType data)
//这里头节点在上边  一直改变
{
	

	LinkStackPtr newst = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!newst)
	{
		return ERROR;
	}
	else {
		newst->data = data;

		newst->next = s->top->next;
		s->top->next = newst;//头指针指向头结点 一直改变
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
		printf("||-->栈空!\n");
	}
	return 0;
}

//清空栈
Status Clear(LinkStack* s)
{
	double data;
	
	printf("||-->栈内元素：\n");

	while (!IsEmpty(s))
	{
		Pop(s, &data);
		printf("%d ", data);
	}
	printf("\n");
}

//销毁栈
Status Destroy(LinkStack* s)
{
	double data;
	
	printf("||-->栈内元素:");

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




