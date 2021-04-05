#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>           
#include<stdlib.h>
#include "Calculator.h"

int main()
{
	double result;
	while (1)
	{
		if (get())
		{
			translate();//用于translate()的一些函数，负责栈操作
			result = calculate();
			printf("结果:%lf\n", result);
		}
		else
			break;
	}
	return 0;
}