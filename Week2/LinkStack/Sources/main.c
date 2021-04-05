#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "LinkStack.h"
int data;
int main()
{
	int length;
	int menu1 = 1;//菜单选项
	LinkStack STACK;
	STACK.top = NULL;

	//测试创建栈函数
	while (1)
	{
		
		system("cls");
		Menu_hand(); //九功能
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

			
			initLStack(&STACK);
			printf("||-->初始化成功!\n");

			system("pause");
			getchar();
			system("cls");
			break;
		}
		case 2://判空
		{
			if (STACK.top == NULL)
			{
				printf("||-->请先初始化！\n");

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

		case 3://得到栈顶元素
		{
			if (STACK.top== NULL)
			{
				printf("||-->请先初始化！\n");

			}
			else
			{
				if (getTopLStack(&STACK, &data)) {
					printf("||-->栈顶元素为：%d\n", data);
				}
				else {
					printf("||-->栈空！\n");
				}
			}


			system("pause");
			getchar();
			system("cls");
			break;
		}
		case 4://清空栈
		{
			if (STACK.top == NULL)
			{
				printf("||-->请先初始化！\n");

			}
			else {
				clearLStack(&STACK);
				printf("||-->栈已空！\n");
			}
			system("pause");
			getchar();
			system("cls");
			break;
		}
		case 5://销毁栈
		{
			if (STACK.top == NULL)
			{
				printf("||-->请先初始化！\n");

			}
			else {
				destroyLStack(&STACK);
				printf("||-->栈已毁！\n");
			}
			system("pause");
			getchar();
			system("cls");
			break;
		}

		case 6://检测栈长度
		{
			if (STACK.top == NULL)
			{
				printf("||-->请先初始化！\n");

			}
			else {
				LStackLength(&STACK, &length);
				printf("||-- >栈长度为：%d\n", length);
			}
			system("pause");
			getchar();
			system("cls");
			break;
		}
		case 7://入栈

		{
			if (STACK.top == NULL)
			{
				printf("||-->请先初始化！\n");

			}
			else {
				printf("||-->入栈元素：");
				SCANF(&data);
				pushLStack(&STACK, data);
			}
			
			system("pause");
			getchar();
			system("cls");
			break;
		}
		case 8://出栈
		{
			if (STACK.top == NULL)
			{
				printf("||-->请先初始化！\n");

			}
			else {
				if (popLStack(&STACK, &data)) {


					printf("||-->出栈元素为：%d\n", data);
				}
			}
			system("pause");
			getchar();
			system("cls");
			break;
		}

		case 9://遍历栈
		{
			if (STACK.top == NULL)
			{
				printf("||-->请先初始化！\n");

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
			printf("||-->请输入菜单上的可操作数字.\n");
			system("pause");
			break;
		}
		}
	}
}
    