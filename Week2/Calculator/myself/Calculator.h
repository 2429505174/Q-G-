#include<stdio.h>           
#include<stdlib.h>

//����׺ת��Ϊ��׺ʱ�������������������ô������Ҫ�Բ����������ж�Ȼ�������Ӧ�ģ�ջ������

#ifndef CALCULATE 
#define CALCULATE

//ջ�Ĵ�С�����ʽ����Ĵ�С


typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;

typedef double ElemType;
typedef  struct StackNode
{
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;


//���ʽ�ĵ���Ԫ����ʹ�õĽṹ��
typedef struct elem {
	int num ;
	char oper ;
	Status IsNum ;
}Elem;


typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;

//void SCANF(ElemType* e);
double Calculate();
//��ջ
Status Init(LinkStack* s);//��ʼ��ջ


Status Clear(LinkStack* s);//���ջ
Status Destroy(LinkStack* s);//����ջ

Status Push(LinkStack* s, ElemType data);//��ջ
Status Pop(LinkStack* s, ElemType* data);//��ջ
Status IsEmpty(LinkStack* s);//�ж�ջ�Ƿ�Ϊ��






#endif
