#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>             //顺序栈
#include<stdlib.h>
#include "SqStack.h"

extern int sizes;//栈大小
void Menu_hand()
{

    printf("*-----------------------------------------------*\n");
    printf("*\t\t0.exit\t\t\t\t*\n");
    printf("*\t\t1.initStack\t\t\t*\n");
    printf("*\t\t2.isEmptyStack\t\t\t*\n");
    printf("*\t\t3.isFullStack\t\t\t*\n");
    printf("*\t\t4.getTopStack\t\t\t*\n");
    printf("*\t\t5.clearStack\t\t\t*\n");
    printf("*\t\t6.destroyStack\t\t\t*\n");
    printf("*\t\t7.stackLength\t\t\t*\n");
    printf("*\t\t8.pushStack\t\t\t*\n");
    printf("*\t\t9.popStack\t\t\t*\n");
    printf("*\t\t10.PRINT\t\t\t*\n");
    printf("||-->请输入功能菜单序号：");
}

//遍历
void  PRINT(SqStack* s)
{
    int  i;
    if (s->elem) {
        printf("||-->栈内元素为：");
        for (i = 0; i < (s->size); i++)
        {
            printf("%d  ", s->elem[i]);
            
        }
        printf("\n");
    }
    else
    {
        printf("||-->请初始化！\n");
    }
}
//异常值
void SCANF(ElemType* e) {

    int ret;
    ret = scanf("%d", e);
    getchar();
    while (ret != 1)
    {
        while (getchar() != '\n');
        //printf("||-->永远信任用户！\n");
        printf("||-->请规范输入：");
        ret = scanf("%d", e);
    }

}

Status initStack(SqStack* s, int sizes)//初始化栈
{
    s->elem= (int*)malloc(sizeof(int) * sizes);
    s->top = 0;
    s->size = 0;
    

}

Status pushStack(SqStack* s, ElemType data) {
    if (!(s->elem))
    {
        printf("||-->请先初始化！\n");
        return ERROR;
    }
    else
    {
        if (isFullStack(s)) 
        {
            printf("||-->栈已满！\n");
        }
        else{
            s->elem[s->size] = data;
            s->top = data;
            s->size++;
        }

    }
    //printf("%d", s->elem[0]);
    return SUCCESS;
}

Status popStack(SqStack* s, ElemType* data) {
    if (isEmptyStack(s))
    {
        //返回失败
        return ERROR;
    }
    else {

        s->size--;
        return SUCCESS;
    }

}
Status isEmptyStack(SqStack* s) {
    if (s->elem == NULL)
    {
        printf("||-->请先初始化！\n");
        return SUCCESS;
    }
   
    if (s->size == 0)
    {
        return SUCCESS;
    }
    
    return ERROR;
}
Status isFullStack(SqStack* s) {
    if (s->elem == NULL)
    {
        printf("||-->请先初始化！\n");
        return SUCCESS;
    }
 
    if (s->size == sizes)//是否-1
    {
        return SUCCESS;
    }
    return ERROR;
}
Status getTopStack(SqStack* s, ElemType* e) {

    *e = s->top;

    return SUCCESS;
}

Status clearStack(SqStack* s) {
    if (s)
    {
        s->size = 0;
    }
}

Status destroyStack(SqStack* s) {

    s->elem=NULL;
}
Status stackLength(SqStack* s, int* length) {
    *length = s->size;
}




