#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "SqStack.h"
int sizes;
int main() {

	SqStack stack={0 };
		
	int data;
	int length;
	int menu1 = 1;//�˵�ѡ��
	/*initStack(stack, size);
	isEmptyStack(stack);
	isFullStack(stack);
	getTopStack(stack, &data);
	clearStack(stack);
	destroyStack(stack);
	stackLength(stack, &length);
	pushStack(stack, data);
	popStack(stack, &data);*/
	while (1)
	{
		system("cls");
		Menu_hand(); //ʮ����
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
			
			printf("||-->�������ʼ�����ȣ�");
			SCANF(&sizes);
			initStack(&stack,sizes);
			printf("||-->��ʼ���ɹ�!\n");

			system("pause");
			getchar();
			system("cls");
			break;
		}
		case 2://�п�
		{

			printf("%d\n",isEmptyStack(&stack));
			
			system("pause");
			getchar();
			system("cls");
			break;
		}

		case 3://����
		{
			printf("%d\n", isFullStack(&stack));
			system("pause");
			getchar();
			system("cls");


			break;
		}
		case 4://�õ�ջ��Ԫ��
		{
			if (stack.elem == NULL)
			{
				printf("||-->���ȳ�ʼ����\n");
				
			}
			else
			{
				getTopStack(&stack, &data);
				printf("||-->ջ��Ԫ��Ϊ��%d\n", data);
			}
		

			system("pause");
			break;
		}
		case 5://���ջ
		{

			clearStack(&stack);
			printf("||-->�ɹ���\n");
			system("pause");
			getchar();
			system("cls");
			break;
		}
		case 6://����ջ
		{

			destroyStack(&stack);
			printf("||-->�ɹ���\n");
			system("pause");
			getchar();
			system("cls");
			break;
		}

		case 7://���ջ����
		{
			
			stackLength(&stack, &length);
			printf("||-- >ջ����Ϊ��%d\n", length);
			system("pause");
			getchar();
			system("cls");
			break;
		}
		case 8://��ջ

		{
			printf("||-->��ջԪ�أ�");
			SCANF(&data);
			pushStack(&stack, data);
			system("pause");
			getchar();
			system("cls");
			break;
		}
		case 9://��ջ
		{
			if (stack.elem == NULL)
			{
				printf("||-->���ȳ�ʼ����\n");

			}
			else {
				popStack(&stack, &data);
				printf("||-->��ջԪ��Ϊ��%d\n", data);
			}
			system("pause");
			getchar();
			system("cls");
			break;
		}

		case 10://����ջ
		{
			PRINT(&stack);
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