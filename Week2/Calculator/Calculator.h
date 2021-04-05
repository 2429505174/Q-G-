#include<stdio.h>           
#include<stdlib.h>

//将中缀转换为后缀时，如果遇到操作符，那么我们需要对操作符进行判断然后决定相应的（栈）操作
//下面这些函数就是当遇到不同操作符时调用的不同函数，用如其名
//参数意义是“后缀表达式数组的当前尾端下标”，因为*/(都直接入栈所以不需要该参数，=虽然需要知道当前后缀尾端下标，但不需要更改，因为转换已经要结束了
//其他几个函数因为可能改变“后缀表达式数组的当前尾端下标”，所以需要接收指针型参数
#ifndef CALCULATE 
#define CALCULATE

//栈的大小、表达式数组的大小
#define SIZE 1000


typedef enum Status
{
	ERROR = 0, SUCCESS = 1
} Status;
//表达式的单个元素所使用的结构体
typedef struct elem {
	int num ;
	char oper ;
	Status IsNum ;
}Elem;
void Menu();
//get()用于获取用户输入，将用户输入转换为中缀表达式存储在calculate.cpp的中缀表达式数组中
Status GetUn();
//translate()用于将中缀表达式数组中的中缀表达式转换为后缀表达式并存储进后缀表达式数组中
void TranslateUn();
//calculate()将利用后缀表达式数组中的后缀表达式计算出表达式结果并返回
double Calculate();

//translate()的一些函数

void IsAdd(size_t* j);
void IsSub(size_t* j);
void IsMulti(size_t* j);
void IsDiv(size_t* j);
void IsLeft();
void IsRight(size_t* j);
void IsEqual(size_t* j);

#endif
