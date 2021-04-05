#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <ctype.h>  //isdigit函数
#include "Calculator.h"



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


Elem InfixExpression[SIZE]; //中缀表达式
Elem PostfixExpression[SIZE];//后缀表达式



//操作符栈 中缀转后缀使用
char StackOper[SIZE];
extern size_t topOper; //指向栈顶上面的空位
     
void pushOper(char oper)
{
	StackOper[topOper++] = oper;
}
//操作符栈的pop
char popOper()
{
	return StackOper[--topOper];
}




//操作数栈 计算后缀表达式使用
double StackNum[SIZE];
extern size_t topNum ;
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
				else if(input[i - 1] == '=')
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
			else{
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






//中缀表达式转换为后缀表达式并存入后缀表达式数组
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
	pushOper('(');
}

void IsRight(size_t* j)
{
	char oper;
	//如果是正确的表达式，则遇到)时栈内一定有(

	while (topOper > 0)//防止表达式异常
	{
		//获取栈顶元素
		oper = popOper();

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
	while (topOper > 0)
	{
		oper = popOper();
		if (oper == '(') 
		{
			pushOper(oper); //取栈顶操作符 比较 利用规则
			break;
		}
		else //遇到加号 一般都要出栈 除了（
		{
			PostfixExpression[(*j)].IsNum = ERROR;
			PostfixExpression[(*j)++].oper = oper;
		}
	}

	pushOper('+');//最后把加号入栈
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



//乘除优先级大 直接入住
void IsMulti(size_t* j)
{
	char oper;
	while (topOper > 0)
	{
		oper = popOper();
		if (oper != '*' && oper != '/')
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
	pushOper('*');
}

void IsDiv(size_t* j)
{
	char oper;
	while (topOper > 0)
	{
		oper = popOper();
		if (oper != '*' && oper != '/')
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

	pushOper('/');
}



//结束 清空栈
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




//后缀表达式计算规则  使用了后缀表达式数组（内无（） ） 以及操作数栈  而计算机恰巧不能处理（）
double Calculate()
{
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



	//计算
	for (size_t i = 0; i < SIZE; ++i)
	{
		
		if (PostfixExpression[i].oper == '=')
		{
			return popNum(); //取出最后结果
		}
		//数字入栈 
		else if (PostfixExpression[i].IsNum)
		{

			pushNum((double)(PostfixExpression[i].num));
		}
		
		//遇到符号 pop出栈顶两元素进行计算并将结果重新压入栈
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