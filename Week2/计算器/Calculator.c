#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <ctype.h>  //isdigit函数
#include "Calculator.h"


Elem InfixExpression[SIZE]; //中缀表达式
Elem PostfixExpression[SIZE];//后缀表达式

//操作符栈，topOper指向操作符栈的栈顶（即栈中最上面那个元素的上面那个空位置）
char StackOper[SIZE];
size_t topOper = 0;


//操作符 栈的push
void pushOper(char oper)
{
	StackOper[topOper++] = oper;
}
//操作符栈的pop
char popOper()
{
	return StackOper[--topOper];
}



//操作数栈，topNum指向操作数栈的栈顶
double StackNum[SIZE];
size_t topNum = 0;
//操作数栈的push
void pushNum(double e)
{
	StackNum[topNum++] = e;//后加
}
//操作数栈的pop
double popNum()
{
	return StackNum[--topNum];  //先减
}





Status get()
{
	//用于保存用户输入的“字符”
	char input[SIZE * 10];

	printf("输入0退出！\n");
	printf("结尾请输入'='！！\n");
	
	//通过fgets函数获取用户输入 stdin 起重要作用
	fgets(input, sizeof(input) / sizeof(char), stdin);


	//键入的是'n'则返回ERROR
	if (input[0] == '0')
		return ERROR;
	
	int num = 0;
	//遍历整个input数组
	for (unsigned int i = 0, j = 0; i < SIZE * 10; i++)
	{
		//若当前字符为数字字符，则算出当前数字字符与其“左右”的数字字符一起组成了一个什么数
		if (isdigit(input[i]))
		{
			num = num * 10 + input[i] - '0';  //获取数字
		}
		
		else
		{
			//若当前字符为'='则表示表达式结束
			if (input[i] == '=')
			{
				//若表达式'='之前的那个字符不是')'则必然是一个数字字符
				if (input[i - 1] != ')')
				{
					InfixExpression[j].IsNum = SUCCESS;
					InfixExpression[j++].num = num;  //先赋值后++
					num = 0;   //num重置 
				}
				//将'='存入中缀表达式数组并跳出对input[]的遍历
				InfixExpression[j].IsNum = ERROR;
				InfixExpression[j++].oper = '=';
				break;
			}
			//'('是输入的又一特例，'('的  前一个  字符理应为运算符，
			else if (input[i] == '(')
			{
				InfixExpression[j].IsNum = ERROR;
				InfixExpression[j++].oper = '(';
			}
			else if (input[i] == ')' && input[i - 1] == ')')
			{

				InfixExpression[j].IsNum = ERROR;
				InfixExpression[j++].oper = ')';

			}
			//除去上述特例，不论是运算符还是')'，其前一个为数字字符，则储存两个
			else
			{
				InfixExpression[j].IsNum = SUCCESS;
				InfixExpression[j++].num = num;
				num = 0;
				InfixExpression[j].IsNum = ERROR;
				InfixExpression[j++].oper = input[i];
			}
		}
	}


	//输出中缀表达式
	for (size_t i = 0; i < SIZE; ++i)
	{
		if (!InfixExpression[i].IsNum && InfixExpression[i].oper == '=')
		{
			printf("%c\n", '=');
			break;
		}
		else if (InfixExpression[i].IsNum)
		{
			printf("%d", InfixExpression[i].num);
		}
		else
		{
			printf("%c", InfixExpression[i].oper);
		}

	}
	return SUCCESS;
}








//translate()函数的定义，其用途说明在Calculator.h中
void translate()
{
	//中缀表达式转换为后缀表达式并存入后缀表达式数组
	//i为中缀表达式数组下标，j为后缀表达式数组下标
	for (size_t i = 0, j = 0; i < SIZE; ++i)
	{
		//遇到数字入 操作数栈
		if (InfixExpression[i].IsNum)
		{
			PostfixExpression[j].IsNum = SUCCESS;
			PostfixExpression[j++].num = InfixExpression[i].num;
		}
		//若当前中缀元素不是数字，则判断是否需要输入，i j 不同步

		else
		{
			switch (InfixExpression[i].oper)
			{
			case '(':
				IsLeft();  
				break;
			case ')':
				IsRight(&j); //j可能会发生变化，传地址
				break;
			case '+':
				IsAdd(&j);  
				break;
			case '-':
				IsSub(&j);  
				break;
			case '*':
				IsMulti();  //优先级大
				break;
			case '/':
				IsDiv();  //当前元素为'/'时调用IsDiv()，因为'/'直接入栈，所以j不会发生变化，不需要传递
				break;
			case '=':   
				IsEqual(&j);
				return;
			}
		}
	}
}



//直接push
void IsLeft()
{
	pushOper('(');
}

//如果是')'则弹出栈顶元素直至栈顶元素为'('，当栈顶元素为'('时弹出并丢弃
void IsRight(size_t* j)
{
	char oper;
	//如果是正确的表达式，则遇到)时栈内一定有(
	while (topOper > 0)
	{
		//获取栈顶元素
		oper = popOper();

		//如果是'('则返回
		if (oper == '(')
			return;
		//如果不是'('则将该操作符“输出”至后缀表达式
		else
		{
			PostfixExpression[(*j)].IsNum = ERROR;
			PostfixExpression[(*j)++].oper = oper;
		}
	}
}




void IsAdd(size_t* j)
{
	char oper;
	while (topOper > 0)
	{
		oper = popOper();
		if (oper == '(')
		{
			pushOper(oper);
			break;
		}
		else
		{
			PostfixExpression[(*j)].IsNum = ERROR;
			PostfixExpression[(*j)++].oper = oper;
		}
	}

	pushOper('+');
}

void IsSub(size_t* j)
{
	char oper;
	while (topOper > 0)
	{
		oper = popOper();
		if (oper == '(')
		{
			pushOper(oper);
			break;
		}
		else
		{
			PostfixExpression[(*j)].IsNum = ERROR;
			PostfixExpression[(*j)++].oper = oper;
		}

	}

	pushOper('-');
}

void IsMulti()
{
	pushOper('*');
}

void IsDiv()
{
	pushOper('/');
}

void IsEqual(size_t* j)
{
	char oper;
	while (topOper > 0)
	{
		oper = popOper();
		PostfixExpression[(*j)].IsNum = ERROR;
		PostfixExpression[(*j)++].oper = oper;
	}
	PostfixExpression[(*j)].IsNum = ERROR;
	PostfixExpression[(*j)++].oper = '=';
}


double calculate()
{
	//检查
	printf("后缀表达式为：");
	for (size_t i = 0; i < SIZE; ++i)
	{
		if (!PostfixExpression[i].IsNum && PostfixExpression[i].oper == '=')
		{
			printf("%c\n", '=');
			break;
		}
		else if (PostfixExpression[i].IsNum)
		{
			printf("%d", PostfixExpression[i].num);
		}
		else
		{
			printf("%c", PostfixExpression[i].oper);
		}
	}
	//计算
	for (size_t i = 0; i < SIZE; ++i)
	{
		
		if (PostfixExpression[i].oper == '=')
		{
			return popNum();
		}
		//数字入栈
		else if (PostfixExpression[i].IsNum)
		{

			pushNum((double)(PostfixExpression[i].num));
		}
		
		//是符号 pop出栈顶两元素进行计算并将结果重新压入栈
		else
		{
			//temp用于暂存栈顶两元素的计算结果
			double temp = 0.0;
			//注意，第一次pop右操作数，第二次popN左操作数
			double rear = popNum();
			double front = popNum();

			//根据当前元素选择应进行的运算，并将结果入栈
			switch (PostfixExpression[i].oper)
			{
			case '+':
				temp = front + rear;
				pushNum(temp);
				break;
			case '-':
				temp = front - rear;
				pushNum(temp);
				break;
			case '*':
				temp = front * rear;
				pushNum(temp);
				break;
			case '/':
				temp = front / rear;
				pushNum(temp);
				break;
			}
		}
	}

	return 0;
}