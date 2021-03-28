#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "duLinkedList.h"
int i_count = 0; //计数
DuLNode* Findnode = NULL;
DuLinkedList head = NULL;
DuLNode* pEnd = NULL;
int main()
{
   
    int menu1 = 1;//菜单选项
    int num;

    while (1)
    {
        system("cls");
        Menu_hand(); //十功能
        SCANF(&menu1);
        switch (menu1)
        {
        case 0:
        {
            system("cls");
            exit(0);
        }
        case 1://创建空链表
        {
            InitList_DuL(&head);

            system("pause");
            getchar();
            system("cls");
            break;
        }
        case 2://销毁链表
        {
            DestroyList_DuL(&head);
            printf("||-->成功!\n");
            system("pause");
            getchar();
            system("cls");
            break;
        }
        case 3://插入p前
        {
                    DuLNode* New = NULL;
                    printf("||-->请输入插入位置所在节点的data：");
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
        case 4://p后插入
        {
            DuLNode* New = NULL;
            printf("||-->请输入插入位置前节点的data：");
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
        case 5://删除节点
        {
            if (head == NULL)
            {
                printf("||-->空链表\n");
            }
            else
            {
                printf("||-->请输入要删除节点的前节点data：");
                SCANF(&num);
                if(SearchList_DuL(head, num)) {
                    DeleteList_DuL(Findnode, &num);//删除pre下一个节点 并返回data
                }
                //printf("||-->删除节点内的data：%d\n", num);
                system("pause");
                break;
            }
            break;
        }
        case 6://遍历链表
        {
            void (*Visit) (ElemType e);//函数指针 声明
            Visit = visit;//赋值
            TraverseList_DuL(head, visit);//引用
            printf("\n");
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
    return 0;
}