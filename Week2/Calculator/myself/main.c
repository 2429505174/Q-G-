#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>           
#include<stdlib.h>
#include "TranslateUn.h"//����calculate
#define SIZE 1000

LinkStack StackOper;

//ȫ�ֱ��� ���ٲ�������
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
			TranslateUn();//��׺���ʽת��Ϊ��׺���ʽ�������׺���ʽ����

			
			RESULT = Calculate();
			printf("||-->���:%lf\n", RESULT);
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