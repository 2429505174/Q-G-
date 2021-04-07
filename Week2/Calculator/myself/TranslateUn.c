#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>           
#include<stdlib.h>
#include "TranslateUn.h"


#define SIZE 1000
extern Elem InfixExpression[SIZE]; //中缀表达式
extern Elem PostfixExpression[SIZE];//后缀表达式
//中缀表达式转换为后缀表达式并存入后缀表达式数组

extern LinkStack  StackOper;

void Menu()
{

	printf("*-----------------------------------------------*\n");
	printf("*---------------*计算器规则*--------------------*\n");


	printf("*\t\t1.仅加减乘除\t\t\t*\n");
	printf("*\t\t2.仅无符号整数\t\t\t*\n");
	printf("*\t\t3.仅英文符号\t\t\t*\n");
	printf("*\t\t4.重启提高正确率\t\t*\n");
	printf("*\t\t5.输入0结束\t\t\t*\n");
	printf("*-----------------------------------------------*\n");
	printf("||-->请输入中缀表达式：");
}


void TranslateUn()
{
	
	//i为中缀表达式数组下标，j为后缀表达式数组下标
	for (size_t i = 0, j = 0; i < SIZE; ++i)
	{
		//遇到数字入
		if (InfixExpression[i].IsNum)
		{
			PostfixExpression[j].IsNum = SUCCESS;
			PostfixExpression[j++].num = InfixExpression[i].num;
		}
		//字符则入操作符栈 根据规则输出到后缀表达式

		else
		{
			switch (InfixExpression[i].oper)
			{
			case '(':
				IsLeft();  //（直接入栈
				break;
			case ')':
				IsRight(&j); //栈内（）之间的操作符全部输出 （）删去
				break;
			case '+':
				IsAdd(&j);
				break;
			case '-':
				IsSub(&j); //同加 
				break;
			case '*':
				IsMulti(&j);  //优先级大
				break;
			case '/':
				IsDiv(&j);  //优先级大
				break;
			case '=':
				IsEqual(&j);
				return;
			}
		}
	}
}


//（）处理
void IsLeft()
{
	pushLStack(&StackOper, '(');
}

void IsRight(size_t* j)
{
	char oper;
	//如果是正确的表达式，则遇到)时栈内一定有(

	while (!isEmptyLStack(&StackOper))//防止表达式异常
	{
		//获取栈顶元素
		popLStack(&StackOper, &oper);

		//如果是'('则返回
		if (oper == '(')
			return;

		else
		{
			PostfixExpression[(*j)].IsNum = ERROR;
			PostfixExpression[(*j)++].oper = oper;
		}
	}
}
//加减相同
void IsAdd(size_t* j)
{
	char oper;
	while (!isEmptyLStack(&StackOper))
	{
		popLStack(&StackOper, &oper);
		if (oper == '(')
		{
			pushLStack(&StackOper, oper); //取栈顶操作符 比较 利用规则
			break;
		}
		else //遇到加号 一般都要出栈 除了（
		{
			PostfixExpression[(*j)].IsNum = ERROR;
			PostfixExpression[(*j)++].oper = oper;
		}
	}
	pushLStack(&StackOper, '+');
	//最后把加号入栈
}

void IsSub(size_t* j)
{
	char oper;
	while (!isEmptyLStack(&StackOper))
	{
		popLStack(&StackOper, &oper);
		if (oper == '(')
		{
			pushLStack(&StackOper, oper);
			break;
		}
		else
		{
			PostfixExpression[(*j)].IsNum = ERROR;
			PostfixExpression[(*j)++].oper = oper;
		}

	}
	pushLStack(&StackOper, '-');
	
}



//乘除优先级大 直接入住
void IsMulti(size_t* j)
{
	char oper;
	while (!isEmptyLStack(&StackOper))
	{
		popLStack(&StackOper, &oper);
		if (oper != '*' && oper != '/')
		{
			pushLStack(&StackOper, oper);
			
			break;
		}
		else
		{
			PostfixExpression[(*j)].IsNum = ERROR;
			PostfixExpression[(*j)++].oper = oper;
		}


	}
	pushLStack(&StackOper, '*');
}

void IsDiv(size_t* j)
{
	char oper;
	while (!isEmptyLStack(&StackOper))
	{
		popLStack(&StackOper, &oper);
		if (oper != '*' && oper != '/')
		{
			pushLStack(&StackOper, oper);
			break;
		}
		else
		{
			PostfixExpression[(*j)].IsNum = ERROR;
			PostfixExpression[(*j)++].oper = oper;
		}

	}
	pushLStack(&StackOper, '/');
	
}



//结束 清空栈
void IsEqual(size_t* j)
{
	char oper;
	while (!isEmptyLStack(&StackOper))
	{
		popLStack(&StackOper, &oper);
		PostfixExpression[(*j)].IsNum = ERROR;
		PostfixExpression[(*j)++].oper = oper;
	}
	PostfixExpression[(*j)].IsNum = ERROR;
	PostfixExpression[(*j)++].oper = '=';
}




Status initLStack(LinkStack* s) {

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
Status pushLStack(LinkStack* s, ElemType data)
//这里头节点在上边  一直改变
{
	if (!(s->top))
	{
		printf("||-->请先初始化！\n");
		return ERROR;
	}

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

Status popLStack(LinkStack* s, ElemType* data)
{
	
	if (!isEmptyLStack(s))
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
Status clearLStack(LinkStack* s)
{
	double data;
	if (!(s->top))
	{
		printf("||-->请先初始化！\n");
		return ERROR;
	}
	printf("||-->栈内元素：\n");

	while (!isEmptyLStack(s))
	{
		popLStack(s, &data);
		printf("%d ", data);
	}
	printf("\n");
}

//销毁栈
Status destroyLStack(LinkStack* s)
{
	double data;
	if (!(s->top))
	{
		printf("||-->请先初始化！\n");
		return ERROR;
	}
	printf("||-->栈内元素:");

	while (!isEmptyLStack(s))
	{
		popLStack(s, &data);
		printf("%d ", data);
	}
	printf("\n");
	s->top = NULL;
	return SUCCESS;
}

Status isEmptyLStack(LinkStack* s)
{


	if (s->top->next == NULL)
	{
		return SUCCESS;
	}
	else {

		return ERROR;
	}
}
