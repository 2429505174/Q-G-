#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>           
#include<stdlib.h>
#include "TranslateUn.h"//声明calculate
#define SIZE 1000

LinkStack StackOper;

//全局变量 减少参数传递
int main()
{
	double RESULT;
	
	while (1)
	{
		RESULT = 0;
		Menu();
		
		if (GetUn())
		{
			StackOper.top = NULL;
			initLStack(&StackOper);
			TranslateUn();//中缀表达式转换为后缀表达式并存入后缀表达式数组

			
			RESULT = Calculate();
			printf("||-->结果:%lf\n", RESULT);
			system("pause");
			getchar();
			system("cls");
		}
		else
			break;
	}
	system("pause");
	return 0;
}