#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>           
#include<stdlib.h>
#include "TranslateUn.h"


#define SIZE 1000
extern Elem InfixExpression[SIZE]; //��׺���ʽ
extern Elem PostfixExpression[SIZE];//��׺���ʽ
//��׺���ʽת��Ϊ��׺���ʽ�������׺���ʽ����

extern LinkStack  StackOper;

void Menu()
{

	printf("*-----------------------------------------------*\n");
	printf("*---------------*����������*--------------------*\n");


	printf("*\t\t1.���Ӽ��˳�\t\t\t*\n");
	printf("*\t\t2.���޷�������\t\t\t*\n");
	printf("*\t\t3.��Ӣ�ķ���\t\t\t*\n");
	printf("*\t\t4.���������ȷ��\t\t*\n");
	printf("*\t\t5.����0����\t\t\t*\n");
	printf("*-----------------------------------------------*\n");
	printf("||-->��������׺���ʽ��");
}


void TranslateUn()
{
	
	//iΪ��׺���ʽ�����±꣬jΪ��׺���ʽ�����±�
	for (size_t i = 0, j = 0; i < SIZE; ++i)
	{
		//����������
		if (InfixExpression[i].IsNum)
		{
			PostfixExpression[j].IsNum = SUCCESS;
			PostfixExpression[j++].num = InfixExpression[i].num;
		}
		//�ַ����������ջ ���ݹ����������׺���ʽ

		else
		{
			switch (InfixExpression[i].oper)
			{
			case '(':
				IsLeft();  //��ֱ����ջ
				break;
			case ')':
				IsRight(&j); //ջ�ڣ���֮��Ĳ�����ȫ����� ����ɾȥ
				break;
			case '+':
				IsAdd(&j);
				break;
			case '-':
				IsSub(&j); //ͬ�� 
				break;
			case '*':
				IsMulti(&j);  //���ȼ���
				break;
			case '/':
				IsDiv(&j);  //���ȼ���
				break;
			case '=':
				IsEqual(&j);
				return;
			}
		}
	}
}


//��������
void IsLeft()
{
	pushLStack(&StackOper, '(');
}

void IsRight(size_t* j)
{
	char oper;
	//�������ȷ�ı��ʽ��������)ʱջ��һ����(

	while (!isEmptyLStack(&StackOper))//��ֹ���ʽ�쳣
	{
		//��ȡջ��Ԫ��
		popLStack(&StackOper, &oper);

		//�����'('�򷵻�
		if (oper == '(')
			return;

		else
		{
			PostfixExpression[(*j)].IsNum = ERROR;
			PostfixExpression[(*j)++].oper = oper;
		}
	}
}
//�Ӽ���ͬ
void IsAdd(size_t* j)
{
	char oper;
	while (!isEmptyLStack(&StackOper))
	{
		popLStack(&StackOper, &oper);
		if (oper == '(')
		{
			pushLStack(&StackOper, oper); //ȡջ�������� �Ƚ� ���ù���
			break;
		}
		else //�����Ӻ� һ�㶼Ҫ��ջ ���ˣ�
		{
			PostfixExpression[(*j)].IsNum = ERROR;
			PostfixExpression[(*j)++].oper = oper;
		}
	}
	pushLStack(&StackOper, '+');
	//���ѼӺ���ջ
}

void IsSub(size_t* j)
{
	char oper;
	while (!isEmptyLStack(&StackOper))
	{
		popLStack(&StackOper, &oper);
		if (oper == '(')
		{
			pushLStack(&StackOper, oper);
			break;
		}
		else
		{
			PostfixExpression[(*j)].IsNum = ERROR;
			PostfixExpression[(*j)++].oper = oper;
		}

	}
	pushLStack(&StackOper, '-');
	
}



//�˳����ȼ��� ֱ����ס
void IsMulti(size_t* j)
{
	char oper;
	while (!isEmptyLStack(&StackOper))
	{
		popLStack(&StackOper, &oper);
		if (oper != '*' && oper != '/')
		{
			pushLStack(&StackOper, oper);
			
			break;
		}
		else
		{
			PostfixExpression[(*j)].IsNum = ERROR;
			PostfixExpression[(*j)++].oper = oper;
		}


	}
	pushLStack(&StackOper, '*');
}

void IsDiv(size_t* j)
{
	char oper;
	while (!isEmptyLStack(&StackOper))
	{
		popLStack(&StackOper, &oper);
		if (oper != '*' && oper != '/')
		{
			pushLStack(&StackOper, oper);
			break;
		}
		else
		{
			PostfixExpression[(*j)].IsNum = ERROR;
			PostfixExpression[(*j)++].oper = oper;
		}

	}
	pushLStack(&StackOper, '/');
	
}



//���� ���ջ
void IsEqual(size_t* j)
{
	char oper;
	while (!isEmptyLStack(&StackOper))
	{
		popLStack(&StackOper, &oper);
		PostfixExpression[(*j)].IsNum = ERROR;
		PostfixExpression[(*j)++].oper = oper;
	}
	PostfixExpression[(*j)].IsNum = ERROR;
	PostfixExpression[(*j)++].oper = '=';
}




Status initLStack(LinkStack* s) {

	LinkStackPtr stack = (LinkStackPtr)malloc(sizeof(StackNode));
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
	
	if (!isEmptyLStack(s))
	{
		LinkStackPtr tmpst = (LinkStackPtr)malloc(sizeof(StackNode));
		tmpst = s->top->next;
		*data = tmpst->data;
		s->top->next = tmpst->next;
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
	double data;
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
	double data;
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

Status isEmptyLStack(LinkStack* s)
{


	if (s->top->next == NULL)
	{
		return SUCCESS;
	}
	else {

		return ERROR;
	}
}
