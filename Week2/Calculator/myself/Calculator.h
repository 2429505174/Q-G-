#include<stdio.h>           
#include<stdlib.h>

//将中缀转换为后缀时，如果遇到操作符，那么我们需要对操作符进行判断然后决定相应的（栈）操作

#ifndef CALCULATE 
#define CALCULATE

//栈的大小、表达式数组的大小


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


//表达式的单个元素所使用的结构体
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
//链栈
Status Init(LinkStack* s);//初始化栈


Status Clear(LinkStack* s);//清空栈
Status Destroy(LinkStack* s);//销毁栈

Status Push(LinkStack* s, ElemType data);//入栈
Status Pop(LinkStack* s, ElemType* data);//出栈
Status IsEmpty(LinkStack* s);//判断栈是否为空






#endif
