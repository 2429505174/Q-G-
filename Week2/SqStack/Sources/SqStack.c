#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>             //˳��ջ
#include<stdlib.h>
#include "SqStack.h"

extern int sizes;//ջ��С
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
    printf("||-->�����빦�ܲ˵���ţ�");
}

//����
void  PRINT(SqStack* s)
{
    int  i;
    if (s->elem) {
        printf("||-->ջ��Ԫ��Ϊ��");
        for (i = 0; i < (s->size); i++)
        {
            printf("%d  ", s->elem[i]);
            
        }
        printf("\n");
    }
    else
    {
        printf("||-->���ʼ����\n");
    }
}
//�쳣ֵ
void SCANF(ElemType* e) {

    int ret;
    ret = scanf("%d", e);
    getchar();
    while (ret != 1)
    {
        while (getchar() != '\n');
        //printf("||-->��Զ�����û���\n");
        printf("||-->��淶���룺");
        ret = scanf("%d", e);
    }

}

Status initStack(SqStack* s, int sizes)//��ʼ��ջ
{
    s->elem= (int*)malloc(sizeof(int) * sizes);
    s->top = 0;
    s->size = 0;
    

}

Status pushStack(SqStack* s, ElemType data) {
    if (!(s->elem))
    {
        printf("||-->���ȳ�ʼ����\n");
        return ERROR;
    }
    else
    {
        if (isFullStack(s)) 
        {
            printf("||-->ջ������\n");
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
        //����ʧ��
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
        printf("||-->���ȳ�ʼ����\n");
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
        printf("||-->���ȳ�ʼ����\n");
        return SUCCESS;
    }
 
    if (s->size == sizes)//�Ƿ�-1
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




