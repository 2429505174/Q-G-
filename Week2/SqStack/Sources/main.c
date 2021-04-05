#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "SqStack.h"
int sizes;
int main() {

	SqStack stack={0 };
		
	int data;
	int length;
	int menu1 = 1;//菜单选项
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
		Menu_hand(); //十功能
		SCANF(&menu1);
		switch (menu1)
		{
		case 0:
		{
			printf("||-->结束!\n");
			system("pause");
			getchar();
			exit(0);
		}
		case 1: //初始化
		{
			
			printf("||-->请输入初始化长度：");
			SCANF(&sizes);
			initStack(&stack,sizes);
			printf("||-->初始化成功!\n");

			system("pause");
			getchar();
			system("cls");
			break;
		}
		case 2://判空
		{

			printf("%d\n",isEmptyStack(&stack));
			
			system("pause");
			getchar();
			system("cls");
			break;
		}

		case 3://判满
		{
			printf("%d\n", isFullStack(&stack));
			system("pause");
			getchar();
			system("cls");


			break;
		}
		case 4://得到栈顶元素
		{
			if (stack.elem == NULL)
			{
				printf("||-->请先初始化！\n");
				
			}
			else
			{
				getTopStack(&stack, &data);
				printf("||-->栈顶元素为：%d\n", data);
			}
		

			system("pause");
			break;
		}
		case 5://清空栈
		{

			clearStack(&stack);
			printf("||-->成功！\n");
			system("pause");
			getchar();
			system("cls");
			break;
		}
		case 6://销毁栈
		{

			destroyStack(&stack);
			printf("||-->成功！\n");
			system("pause");
			getchar();
			system("cls");
			break;
		}

		case 7://检测栈长度
		{
			
			stackLength(&stack, &length);
			printf("||-- >栈长度为：%d\n", length);
			system("pause");
			getchar();
			system("cls");
			break;
		}
		case 8://入栈

		{
			printf("||-->入栈元素：");
			SCANF(&data);
			pushStack(&stack, data);
			system("pause");
			getchar();
			system("cls");
			break;
		}
		case 9://出栈
		{
			if (stack.elem == NULL)
			{
				printf("||-->请先初始化！\n");

			}
			else {
				popStack(&stack, &data);
				printf("||-->出栈元素为：%d\n", data);
			}
			system("pause");
			getchar();
			system("cls");
			break;
		}

		case 10://遍历栈
		{
			PRINT(&stack);
			system("pause");
			getchar();
			system("cls");
			break;
		}
		default:
		{
			printf("||-->请输入菜单上的可操作数字.\n");
			system("pause");
			break;
		}
		}
	}
}