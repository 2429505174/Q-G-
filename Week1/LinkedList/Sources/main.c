#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "linkedList.h"

//ȫ�ֱ���
int i_count = 0; //����
LinkedList L;//ͷָ��
LNode* pEnd = NULL;
LNode* Pre = NULL;
//void (*visit)(ElemType e) {
//
//	printf("%d", e);
//
//}
int main() {
	ElemType e;
	int menu1 = 1;//�˵�ѡ��
	int index = 0;//�ڵ��±�
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
			InitList(&L);
			printf("||-->�ɹ�!\n");

			system("pause");
			getchar();
			system("cls");
			break;
		}
		case 2://����
		{
			DestroyList(&L);
			printf("\n||-->�ɹ�!\n");
			system("pause");
			getchar();
			system("cls");
			break;
		}

		case 3://����
		{
			LNode* New = NULL;
			printf("||-->������pre��data��");
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
		case 4://ɾ��
		{

			printf("||-->������Ҫɾ���ڵ��ǰ�ڵ�data��");
			SCANF(&e);
			//FindPre(L,Index);
			if (SearchList(L, e))
			{
				DeleteList(Pre, &e);//ɾ��pre��һ���ڵ� ������data
			}//printf("||-->ɾ���ڵ��ڵ�data��%d\n", e);
			system("pause");
			break;
		}
		case 5://����
		{
			void (*Visit) (ElemType e);
			Visit = visit;
			if (L)
			{
				TraverseList(L->next, Visit);
			}
			else
			{
				printf("||-->��ͷָ�룡\n");
			}
			printf("\n");
			system("pause");
			getchar();
			system("cls");
			break;
		}
		case 6://SearchList
		{
		
			printf("||-->������Ҫ���ҽڵ��data��");
			SCANF(&e);
			e=SearchList(L, e);
			printf("%d\n", e);
			system("pause");
			getchar();
			system("cls");
			break;
		}
		
			case 7://��ת����
			{

				ReverseList(&L);

				system("pause");
				getchar();
				system("cls");
				break;
			}
			case 8://ѭ��
			{
				LoopList(L);
				printf("||-->��ѭ����");
				system("pause");
				getchar();
				system("cls");
				break;
			}
			case 9://��ѭ��
			{
				UnLoopList(L);
				printf("||-->�Ѳ�ѭ����");
				system("pause");
				getchar();
				system("cls");
				break;
			}

			case 10://�ж�ѭ��
			{
				IsLoopList(L);
				system("pause");
				getchar();
				system("cls");
				break;
			}
			case 11://��ż�ڵ㽻��
			{
				LNode* Head;
				Head=ReverseEvenList(&L);
				printf("\n������data��");
				TraverseList(Head,  (*visit));

			
				system("pause");
				getchar();
				system("cls");
				break;
			}
			case 12://�м���
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
				printf("||-->������˵��ϵĿɲ�������.\n");
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

		//printf("����Ҫɾ����Ԫ�أ�");
		//scanf("%d", &e);
		//DeleteList(Pre, &e);
		//printf("% d", e);

		//TraverseList(L, (*visit)(e));
		//SearchList(L, e);
		//DestroyList(&L);
	}
	}
}