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
			translate();//����translate()��һЩ����������ջ����
			result = calculate();
			printf("���:%lf\n", result);
		}
		else
			break;
	}
	return 0;
}