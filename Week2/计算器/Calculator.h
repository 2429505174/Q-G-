#include<stdio.h>           
#include<stdlib.h>

//����׺ת��Ϊ��׺ʱ�������������������ô������Ҫ�Բ����������ж�Ȼ�������Ӧ�ģ�ջ������
//������Щ�������ǵ�������ͬ������ʱ���õĲ�ͬ��������������
//���������ǡ���׺���ʽ����ĵ�ǰβ���±ꡱ����Ϊ*/(��ֱ����ջ���Բ���Ҫ�ò�����=��Ȼ��Ҫ֪����ǰ��׺β���±꣬������Ҫ���ģ���Ϊת���Ѿ�Ҫ������
//��������������Ϊ���ܸı䡰��׺���ʽ����ĵ�ǰβ���±ꡱ��������Ҫ����ָ���Ͳ���
#ifndef CALCULATE 
#define CALCULATE

//ջ�Ĵ�С�����ʽ����Ĵ�С
#define SIZE 1000


typedef enum Status
{
	ERROR = 0, SUCCESS = 1
} Status;
//���ʽ�ĵ���Ԫ����ʹ�õĽṹ��
typedef struct elem {
	int num ;
	char oper ;
	Status IsNum ;
}Elem;
void Menu();
//get()���ڻ�ȡ�û����룬���û�����ת��Ϊ��׺���ʽ�洢��calculate.cpp����׺���ʽ������
Status GetUn();
//translate()���ڽ���׺���ʽ�����е���׺���ʽת��Ϊ��׺���ʽ���洢����׺���ʽ������
void TranslateUn();
//calculate()�����ú�׺���ʽ�����еĺ�׺���ʽ��������ʽ���������
double Calculate();

//translate()��һЩ����

void IsAdd(size_t* j);
void IsSub(size_t* j);
void IsMulti(size_t* j);
void IsDiv(size_t* j);
void IsLeft();
void IsRight(size_t* j);
void IsEqual(size_t* j);

#endif
