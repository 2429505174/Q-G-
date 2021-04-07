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


//表达式的单个元素所使用的结构体
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

Status initLStack(LinkStack* s);//初始化栈
Status isEmptyLStack(LinkStack* s);//判断栈是否为空

Status clearLStack(LinkStack* s);//清空栈
Status destroyLStack(LinkStack* s);//销毁栈

Status pushLStack(LinkStack* s, ElemType data);//入栈
Status popLStack(LinkStack* s, ElemType* data);//出栈



void IsAdd(size_t* j);
void IsSub(size_t* j);
void IsMulti(size_t* j);
void IsDiv(size_t* j);
void IsLeft();
void IsRight(size_t* j);
void IsEqual(size_t* j);

#endif