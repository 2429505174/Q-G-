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
    printf("||-->�����빦�ܲ˵���ţ�");
}

void  PRINT(LinkStack* s)
{
    int  i;
    LinkStackPtr temp = s->top->next;
    if (s->top->next) {
        printf("||-->ջ��Ԫ��Ϊ��");
        for (i = 0; i < (s->count); i++)
        {
            printf("%d  ", temp->data);
            temp = temp->next;

        }
        printf("\n");
    }
    else
    {
        printf("||-->ջ�գ�\n");
    }
}
//�쳣ֵ
void SCANF(ElemType* e) {

    int ret;
    char ch;
    ret = scanf("%d", e);
 
    if (ret == 1) {
        ch = getchar();
        if (ch == ' ' || ch == '\n') {

        }
        else {
            printf("||-->�������쳣!\n");
            while (getchar() != '\n');
            printf("||-->�Ƿ����(Y):");
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
        //printf("||-->��Զ�����û���\n");
        printf("||-->��淶���룺");
        ret = scanf("%d", e);

        if (ret == 1) {
            ch = getchar();
            if (ch == ' ' || ch == '\n') {

            }
            else {
                printf("||-->�������쳣!\n");
                while (getchar() != '\n');
                printf("||-->�Ƿ����(Y):");
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
//��ʼ����ͷָ��
Status initLStack(LinkStack* s){
   
    LinkStackPtr stack= (LinkStackPtr)malloc(sizeof(StackNode));
    if (!stack)
    {
        return ERROR;
    }
    else {
        s->count = 0;
        s->top = stack; 
        //stack->data = 0;ͷָ�벻��Ԫ��
        s->top->next = NULL; //Ϊ��һ���ڵ�ָ�����׼��
    }
  
       
    return SUCCESS;
}
Status pushLStack(LinkStack* s, ElemType data)
//����ͷ�ڵ����ϱ�  һֱ�ı�
{
    if (!(s->top))
    {
        printf("||-->���ȳ�ʼ����\n");
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
        s->top->next = newst;//ͷָ��ָ��ͷ��� һֱ�ı�
        s->count++;
        return SUCCESS;
    }
  
}

Status popLStack(LinkStack* s, ElemType* data)
{
    if (!(s->top))
    {
        printf("||-->���ȳ�ʼ����\n");
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
        printf("||-->ջ��!\n");
    }
    return 0;
}

//���ջ
Status clearLStack(LinkStack* s)
{
    if (!(s->top))
    {
        printf("||-->���ȳ�ʼ����\n");
        return ERROR;
    }
    printf("||-->ջ��Ԫ�أ�\n");

    while (!isEmptyLStack(s))
    {
        popLStack(s, &data);
        printf("%d ", data);
    }
    printf("\n");
}

//����ջ
Status destroyLStack(LinkStack* s)
{
    if (!(s->top))
    {
        printf("||-->���ȳ�ʼ����\n");
        return ERROR;
    }
    printf("||-->ջ��Ԫ��:");

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



//ȡջ��Ԫ�أ���ȡ��ջ��Ԫ�ص�ֵ��ȡ��֮�󣬸�Ԫ�أ���Ȼ����ջ�С��ɹ�����Ԫ��ֵ��ʧ�������ʾ��Ϣ�������� -1
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
