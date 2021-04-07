#include<stdio.h>           
#include<stdlib.h>


#ifndef TRANSLATE 
#define TRANSLATE 
typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;


typedef char ElemType;


typedef  struct StackNode
{
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;


//���ʽ�ĵ���Ԫ����ʹ�õĽṹ��
typedef struct elem {
	int num;
	char oper;
	Status IsNum;
}Elem;


typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;

void Menu();
void TranslateUn();
double Calculate();

Status initLStack(LinkStack* s);//��ʼ��ջ
Status isEmptyLStack(LinkStack* s);//�ж�ջ�Ƿ�Ϊ��

Status clearLStack(LinkStack* s);//���ջ
Status destroyLStack(LinkStack* s);//����ջ

Status pushLStack(LinkStack* s, ElemType data);//��ջ
Status popLStack(LinkStack* s, ElemType* data);//��ջ



void IsAdd(size_t* j);
void IsSub(size_t* j);
void IsMulti(size_t* j);
void IsDiv(size_t* j);
void IsLeft();
void IsRight(size_t* j);
void IsEqual(size_t* j);

#endif