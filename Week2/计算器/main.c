#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>           
#include<stdlib.h>
#include "Calculator.h"
size_t topOper = 0;
size_t topNum = 0;
int main()
{
	double result;
	while (1)
	{
		topNum = 0;
		topOper = 0;
		result = 0;
		Menu();
		
		if (GetUn())
		{
			TranslateUn();//中缀表达式转换为后缀表达式并存入后缀表达式数组
			result = Calculate();
			printf("||-->结果:%lf\n", result);
			system("pause");
			getchar();
			system("cls");
		}
		else
			break;
	}
	return 0;
}