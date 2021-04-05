#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status
{
	ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct SqStack
{
	ElemType* elem; //�൱������
	int top; //ջ��Ԫ��
	int size;
} SqStack;


//���������˳��ջ
Status initStack(SqStack* s, int sizes);//��ʼ��ջ
Status isEmptyStack(SqStack* s);//�ж�ջ�Ƿ�Ϊ��
Status isFullStack(SqStack* s);//�ж�ջ��
Status getTopStack(SqStack* s, ElemType* e); //�õ�ջ��Ԫ��
Status clearStack(SqStack* s);//���ջ
Status destroyStack(SqStack* s);//����ջ
Status stackLength(SqStack* s, int* length);//���ջ����
Status pushStack(SqStack* s, ElemType data);//��ջ
Status popStack(SqStack* s, ElemType* data);//��ջ

void SCANF(ElemType* e);//�쳣ֵ����
void PRINT(SqStack* s);//����
void Menu_hand();//�˵�
#endif 