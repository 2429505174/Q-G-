#include<stdio.h>           
#include<stdlib.h>
//#include "LinkStack.h"
#include "Calculator.h"

#define SIZE 1000
Elem InfixExpression[SIZE]; //中缀表达式
Elem PostfixExpression[SIZE];//后缀表达式
//保存中缀表达式  等待转换 必要性：数字字符转为整形   
Status GetUn()
{
	//用于保存用户输入内容
	char input[SIZE * 10];


	//通过fgets函数获取用户输入 stdin 起重要作用
	fgets(input, sizeof(input) / sizeof(char), stdin);
	int x = 0;
	while (input[x] != '\n')
	{
		x++;
	}
	input[x] = '=';
	//input[x+1] = '\n';



	//键入的是'n'则返回ERROR
	if (input[0] == '0')
		return ERROR;

	int num = 0;
	//遍历整个input数组 储存中缀表达式
	for (size_t i = 0, j = 0; i < SIZE * 10; i++)
	{

		if (isdigit(input[i]))
		{
			num = num * 10 + input[i] - '0';  //获取数字
		}


		//这些都是 数字 字符
		else//数字未处理 这里每个字符都要考虑前面是数字的情况
		{
			//若当前字符为'='则表示表达式结束
			if (input[i] == '=') //=前面 要么是）要么是数字
			{
				//若表达式'='之前的那个字符不是')'则必然是一个数字字符  或者两个==
				if (input[i - 1] != ')')
				{
					InfixExpression[j].IsNum = SUCCESS;
					InfixExpression[j++].num = num;  //先赋值后++
					num = 0;   //num重置 
				}
				else if (input[i - 1] == '=')
				{
					break;
				}
				//将'='存入中缀表达式数组并跳出对input[]的遍历
				InfixExpression[j].IsNum = ERROR;
				InfixExpression[j++].oper = '=';
				break;
			}

			else if (input[i] == '(') //（前一定是操作符 因此不管数字
			{
				InfixExpression[j].IsNum = ERROR;
				InfixExpression[j++].oper = '(';
			}

			//除去上述特例，不论是运算符还是')'，其前一个为数字字符，则储存两个
			else if (isdigit(input[i - 1])) //包含情况： 数字 ）  数字 加减乘除
			{
				InfixExpression[j].IsNum = SUCCESS;
				InfixExpression[j++].num = num;
				num = 0;
				InfixExpression[j].IsNum = ERROR;
				InfixExpression[j++].oper = input[i];
			}




			//下面这个连续两个不是数字 
			else if (input[i] == ')' && input[i - 1] == ')') //））
			{

				InfixExpression[j].IsNum = ERROR;
				InfixExpression[j++].oper = ')';

			}

			//  ）后加减乘除  ）前是数字 或者 ）） 但数字均已处理 且）已输入
			else {
				//下面仅处理 ）后的加减乘除
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
			printf(" %d ", InfixExpression[i].num);
		}
		else
		{
			printf("%c", InfixExpression[i].oper);
		}

	}
	return SUCCESS;
}