#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "duLinkedList.h"
int i_count = 0; //����
DuLNode* Findnode = NULL;
DuLinkedList head = NULL;
DuLNode* pEnd = NULL;
int main()
{
   
    int menu1 = 1;//�˵�ѡ��
    int num;

    while (1)
    {
        system("cls");
        Menu_hand(); //ʮ����
        SCANF(&menu1);
        switch (menu1)
        {
        case 0:
        {
            system("cls");
            exit(0);
        }
        case 1://����������
        {
            InitList_DuL(&head);

            system("pause");
            getchar();
            system("cls");
            break;
        }
        case 2://��������
        {
            DestroyList_DuL(&head);
            printf("||-->�ɹ�!\n");
            system("pause");
            getchar();
            system("cls");
            break;
        }
        case 3://����pǰ
        {
                    DuLNode* New = NULL;
                    printf("||-->���������λ�����ڽڵ��data��");
                    SCANF(&num);
                    //FindPre(L,Index);
                    SearchList_DuL(head, num);
                    New = creatNew();
                    InsertBeforeList_DuL(Findnode, New);
                    system("pause");
                    getchar();
                    system("cls");
                    break;
        }
        case 4://p�����
        {
            DuLNode* New = NULL;
            printf("||-->���������λ��ǰ�ڵ��data��");
            SCANF(&num);
            //FindPre(L,Index);
            SearchList_DuL(head, num);
            New = creatNew();
            InsertAfterList_DuL(Findnode, New);
            system("pause");
            getchar();
            system("cls");
            break;
        }
        case 5://ɾ���ڵ�
        {
            if (head == NULL)
            {
                printf("||-->������\n");
            }
            else
            {
                printf("||-->������Ҫɾ���ڵ��ǰ�ڵ�data��");
                SCANF(&num);
                if(SearchList_DuL(head, num)) {
                    DeleteList_DuL(Findnode, &num);//ɾ��pre��һ���ڵ� ������data
                }
                //printf("||-->ɾ���ڵ��ڵ�data��%d\n", num);
                system("pause");
                break;
            }
            break;
        }
        case 6://��������
        {
            void (*Visit) (ElemType e);//����ָ�� ����
            Visit = visit;//��ֵ
            TraverseList_DuL(head, visit);//����
            printf("\n");
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
    return 0;
}