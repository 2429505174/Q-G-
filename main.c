#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "linkedList.h"

//全局变量
int i_count = 0; //计数
LinkedList L;//头指针
LNode* pEnd = NULL;
LNode* Pre = NULL;
//void (*visit)(ElemType e) {
//
//	printf("%d", e);
//
//}
int main() {
	ElemType e;
	int menu1 = 1;//菜单选项
	int index = 0;//节点下标
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
			InitList(&L);
			printf("||-->成功!\n");

			system("pause");
			getchar();
			system("cls");
			break;
		}
		case 2://销毁
		{
			DestroyList(&L);
			printf("\n||-->成功!\n");
			system("pause");
			getchar();
			system("cls");
			break;
		}

		case 3://插入
		{
			LNode* New = NULL;
			printf("||-->请输入pre的data：");
			SCANF(&e);
			//FindPre(L,Index);
			SearchList(L, e);
			New = creatNew();
			InsertList(Pre, New);
			system("pause");
			getchar();
			system("cls");


			break;
		}
		case 4://删除
		{

			printf("||-->请输入要删除节点的前节点data：");
			SCANF(&e);
			//FindPre(L,Index);
			if (SearchList(L, e))
			{
				DeleteList(Pre, &e);//删除pre下一个节点 并返回data
			}//printf("||-->删除节点内的data：%d\n", e);
			system("pause");
			break;
		}
		case 5://遍历
		{
			void (*Visit) (ElemType e);
			Visit = visit;
			if (L)
			{
				TraverseList(L->next, Visit);
			}
			else
			{
				printf("||-->空头指针！\n");
			}
			printf("\n");
			system("pause");
			getchar();
			system("cls");
			break;
		}
		case 6://SearchList
		{
		
			printf("||-->请输入要查找节点的data：");
			SCANF(&e);
			e=SearchList(L, e);
			printf("%d\n", e);
			system("pause");
			getchar();
			system("cls");
			break;
		}
		
			case 7://反转链表
			{

				ReverseList(&L);

				system("pause");
				getchar();
				system("cls");
				break;
			}
			case 8://循环
			{
				LoopList(L);
				printf("||-->已循环！");
				system("pause");
				getchar();
				system("cls");
				break;
			}
			case 9://解循环
			{
				UnLoopList(L);
				printf("||-->已不循环！");
				system("pause");
				getchar();
				system("cls");
				break;
			}

			case 10://判断循环
			{
				IsLoopList(L);
				system("pause");
				getchar();
				system("cls");
				break;
			}
			case 11://奇偶节点交换
			{
				LNode* Head;
				Head=ReverseEvenList(&L);
				printf("\n交换后data：");
				TraverseList(Head,  (*visit));

			
				system("pause");
				getchar();
				system("cls");
				break;
			}
			case 12://中间结点
			{
				LNode* Mid;
				Mid=FindMidNode(&L);
				printf("%d\n",Mid->data);
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


		//	}
		//	if (menu2 == 0)
		//		break;
		//break;
		//}
		//ElemType e;
		//LNode* Pre = NULL;
		//LNode* New=NULL;

		//DestroyList(&L);
		//InsertList(Pre,New);

		//printf("输入要删除的元素：");
		//scanf("%d", &e);
		//DeleteList(Pre, &e);
		//printf("% d", e);

		//TraverseList(L, (*visit)(e));
		//SearchList(L, e);
		//DestroyList(&L);
	}
	}
}