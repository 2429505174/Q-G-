#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"
extern int data;

void Menu_hand()
{

    printf("*-----------------------------------------------*\n");
    printf("*\t\t0.exit\t\t\t\t*\n");
    printf("*\t\t1.initLStack\t\t\t*\n");
    printf("*\t\t2.isEmptyLStack\t\t\t*\n");
    printf("*\t\t3.getTopLStack\t\t\t*\n");
    printf("*\t\t4.clearLStack\t\t\t*\n");
    printf("*\t\t5.destroyLStack\t\t\t*\n");
    printf("*\t\t6.LStackLength\t\t\t*\n");
    printf("*\t\t7.pushLStack\t\t\t*\n");
    printf("*\t\t8.popLStack\t\t\t*\n");
    printf("*\t\t9.PRINT\t\t\t\t*\n");
    printf("||-->请输入功能菜单序号：");
}

void  PRINT(LinkStack* s)
{
    int  i;
    LinkStackPtr temp = s->top->next;
    if (s->top->next) {
        printf("||-->栈内元素为：");
        for (i = 0; i < (s->count); i++)
        {
            printf("%d  ", temp->data);
            temp = temp->next;

        }
        printf("\n");
    }
    else
    {
        printf("||-->栈空！\n");
    }
}
//异常值
void SCANF(ElemType* e) {

    int ret;
    char ch;
    ret = scanf("%d", e);
 
    if (ret == 1) {
        ch = getchar();
        if (ch == ' ' || ch == '\n') {

        }
        else {
            printf("||-->输入有异常!\n");
            while (getchar() != '\n');
            printf("||-->是否忽略(Y):");
            scanf("%c", &ch);
            if (ch == 'Y')
            {

            }
            else {
                ret = 0;

            }
        }
    }
    while (ret != 1)
    {

        while (getchar() != '\n');
        //printf("||-->永远信任用户！\n");
        printf("||-->请规范输入：");
        ret = scanf("%d", e);

        if (ret == 1) {
            ch = getchar();
            if (ch == ' ' || ch == '\n') {

            }
            else {
                printf("||-->输入有异常!\n");
                while (getchar() != '\n');
                printf("||-->是否忽略(Y):");
                scanf("%c", &ch);
                if (ch == 'Y'||ch == 'Y')
                {

                }
                else {
                    ret = 0;

                }
            }

        }
    }

}
//初始化，头指针
Status initLStack(LinkStack* s){
   
    LinkStackPtr stack= (LinkStackPtr)malloc(sizeof(StackNode));
    if (!stack)
    {
        return ERROR;
    }
    else {
        s->count = 0;
        s->top = stack; 
        //stack->data = 0;头指针不存元素
        s->top->next = NULL; //为第一个节点指向空做准备
    }
  
       
    return SUCCESS;
}
Status pushLStack(LinkStack* s, ElemType data)
//这里头节点在上边  一直改变
{
    if (!(s->top))
    {
        printf("||-->请先初始化！\n");
        return ERROR;
    }
    
    LinkStackPtr newst = (LinkStackPtr)malloc(sizeof(StackNode));
    if (!newst)
    {
        return ERROR;
    }
    else {
        newst->data = data;

        newst->next = s->top->next;  
        s->top->next = newst;//头指针指向头结点 一直改变
        s->count++;
        return SUCCESS;
    }
  
}

Status popLStack(LinkStack* s, ElemType* data)
{
    if (!(s->top))
    {
        printf("||-->请先初始化！\n");
        return ERROR;
    }
    if (!isEmptyLStack(s))
    {
        LinkStackPtr tmpst = (LinkStackPtr)malloc(sizeof(StackNode));
        tmpst = s->top->next;
        *data = tmpst->data;
        s->top->next= tmpst->next;
        free(tmpst);
        s->count--;
        return SUCCESS;
    }
    else {
        printf("||-->栈空!\n");
    }
    return 0;
}

//清空栈
Status clearLStack(LinkStack* s)
{
    if (!(s->top))
    {
        printf("||-->请先初始化！\n");
        return ERROR;
    }
    printf("||-->栈内元素：\n");

    while (!isEmptyLStack(s))
    {
        popLStack(s, &data);
        printf("%d ", data);
    }
    printf("\n");
}

//销毁栈
Status destroyLStack(LinkStack* s)
{
    if (!(s->top))
    {
        printf("||-->请先初始化！\n");
        return ERROR;
    }
    printf("||-->栈内元素:");

    while (!isEmptyLStack(s))
    {
        popLStack(s, &data);
        printf("%d ", data);
    }
    printf("\n");
    s->top = NULL;
    return SUCCESS;
}

Status isEmptyLStack (LinkStack* s)
{
 
   
    if (s->top->next == NULL)
    {
        return SUCCESS;
    }
    else {

        return ERROR;
    }
}

Status LStackLength(LinkStack* s, ElemType* length) {

    *length = s->count;
}



//取栈顶元素，仅取出栈顶元素的值，取出之后，该元素，任然存在栈中。成功返回元素值，失败输出提示信息，并返回 -1
Status getTopLStack(LinkStack* s, ElemType* e)
{
   
    if (!isEmptyLStack(s))
    {
        *e = s->top->next->data;
        return SUCCESS;
    }
    else {
        return ERROR;
    }
    
}
