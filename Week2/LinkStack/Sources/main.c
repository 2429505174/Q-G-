#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "LinkStack.h"
int data;
int main()
{
	int length;
	int menu1 = 1;//�˵�ѡ��
	LinkStack STACK;
	STACK.top = NULL;

	//���Դ���ջ����
	while (1)
	{
		
		system("cls");
		Menu_hand(); //�Ź���
		SCANF(&menu1);
		switch (menu1)
		{
		case 0:
		{
			printf("||-->����!\n");
			system("pause");
			getchar();
			exit(0);
		}
		case 1: //��ʼ��
		{

			
			initLStack(&STACK);
			printf("||-->��ʼ���ɹ�!\n");

			system("pause");
			getchar();
			system("cls");
			break;
		}
		case 2://�п�
		{
			if (STACK.top == NULL)
			{
				printf("||-->���ȳ�ʼ����\n");

			}
			else
			{
				printf("%d\n", isEmptyLStack(&STACK));
			}
			system("pause");
			getchar();
			system("cls");
			break;
		}

		case 3://�õ�ջ��Ԫ��
		{
			if (STACK.top== NULL)
			{
				printf("||-->���ȳ�ʼ����\n");

			}
			else
			{
				if (getTopLStack(&STACK, &data)) {
					printf("||-->ջ��Ԫ��Ϊ��%d\n", data);
				}
				else {
					printf("||-->ջ�գ�\n");
				}
			}


			system("pause");
			getchar();
			system("cls");
			break;
		}
		case 4://���ջ
		{
			if (STACK.top == NULL)
			{
				printf("||-->���ȳ�ʼ����\n");

			}
			else {
				clearLStack(&STACK);
				printf("||-->ջ�ѿգ�\n");
			}
			system("pause");
			getchar();
			system("cls");
			break;
		}
		case 5://����ջ
		{
			if (STACK.top == NULL)
			{
				printf("||-->���ȳ�ʼ����\n");

			}
			else {
				destroyLStack(&STACK);
				printf("||-->ջ�ѻ٣�\n");
			}
			system("pause");
			getchar();
			system("cls");
			break;
		}

		case 6://���ջ����
		{
			if (STACK.top == NULL)
			{
				printf("||-->���ȳ�ʼ����\n");

			}
			else {
				LStackLength(&STACK, &length);
				printf("||-- >ջ����Ϊ��%d\n", length);
			}
			system("pause");
			getchar();
			system("cls");
			break;
		}
		case 7://��ջ

		{
			if (STACK.top == NULL)
			{
				printf("||-->���ȳ�ʼ����\n");

			}
			else {
				printf("||-->��ջԪ�أ�");
				SCANF(&data);
				pushLStack(&STACK, data);
			}
			
			system("pause");
			getchar();
			system("cls");
			break;
		}
		case 8://��ջ
		{
			if (STACK.top == NULL)
			{
				printf("||-->���ȳ�ʼ����\n");

			}
			else {
				if (popLStack(&STACK, &data)) {


					printf("||-->��ջԪ��Ϊ��%d\n", data);
				}
			}
			system("pause");
			getchar();
			system("cls");
			break;
		}

		case 9://����ջ
		{
			if (STACK.top == NULL)
			{
				printf("||-->���ȳ�ʼ����\n");

			}
			else {
				PRINT(&STACK);
			}
			system("pause");
			getchar();
			system("cls");
			break;
		}
		default:
		{
			printf("||-->������˵��ϵĿɲ�������.\n");
			system("pause");
			break;
		}
		}
	}
}
    