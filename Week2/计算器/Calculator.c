#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <ctype.h>  //isdigit����
#include "Calculator.h"


Elem InfixExpression[SIZE]; //��׺���ʽ
Elem PostfixExpression[SIZE];//��׺���ʽ

//������ջ��topOperָ�������ջ��ջ������ջ���������Ǹ�Ԫ�ص������Ǹ���λ�ã�
char StackOper[SIZE];
size_t topOper = 0;


//������ ջ��push
void pushOper(char oper)
{
	StackOper[topOper++] = oper;
}
//������ջ��pop
char popOper()
{
	return StackOper[--topOper];
}



//������ջ��topNumָ�������ջ��ջ��
double StackNum[SIZE];
size_t topNum = 0;
//������ջ��push
void pushNum(double e)
{
	StackNum[topNum++] = e;//���
}
//������ջ��pop
double popNum()
{
	return StackNum[--topNum];  //�ȼ�
}





Status get()
{
	//���ڱ����û�����ġ��ַ���
	char input[SIZE * 10];

	printf("����0�˳���\n");
	printf("��β������'='����\n");
	
	//ͨ��fgets������ȡ�û����� stdin ����Ҫ����
	fgets(input, sizeof(input) / sizeof(char), stdin);


	//�������'n'�򷵻�ERROR
	if (input[0] == '0')
		return ERROR;
	
	int num = 0;
	//��������input����
	for (unsigned int i = 0, j = 0; i < SIZE * 10; i++)
	{
		//����ǰ�ַ�Ϊ�����ַ����������ǰ�����ַ����䡰���ҡ��������ַ�һ�������һ��ʲô��
		if (isdigit(input[i]))
		{
			num = num * 10 + input[i] - '0';  //��ȡ����
		}
		
		else
		{
			//����ǰ�ַ�Ϊ'='���ʾ���ʽ����
			if (input[i] == '=')
			{
				//�����ʽ'='֮ǰ���Ǹ��ַ�����')'���Ȼ��һ�������ַ�
				if (input[i - 1] != ')')
				{
					InfixExpression[j].IsNum = SUCCESS;
					InfixExpression[j++].num = num;  //�ȸ�ֵ��++
					num = 0;   //num���� 
				}
				//��'='������׺���ʽ���鲢������input[]�ı���
				InfixExpression[j].IsNum = ERROR;
				InfixExpression[j++].oper = '=';
				break;
			}
			//'('���������һ������'('��  ǰһ��  �ַ���ӦΪ�������
			else if (input[i] == '(')
			{
				InfixExpression[j].IsNum = ERROR;
				InfixExpression[j++].oper = '(';
			}
			else if (input[i] == ')' && input[i - 1] == ')')
			{

				InfixExpression[j].IsNum = ERROR;
				InfixExpression[j++].oper = ')';

			}
			//��ȥ�������������������������')'����ǰһ��Ϊ�����ַ����򴢴�����
			else
			{
				InfixExpression[j].IsNum = SUCCESS;
				InfixExpression[j++].num = num;
				num = 0;
				InfixExpression[j].IsNum = ERROR;
				InfixExpression[j++].oper = input[i];
			}
		}
	}


	//�����׺���ʽ
	for (size_t i = 0; i < SIZE; ++i)
	{
		if (!InfixExpression[i].IsNum && InfixExpression[i].oper == '=')
		{
			printf("%c\n", '=');
			break;
		}
		else if (InfixExpression[i].IsNum)
		{
			printf("%d", InfixExpression[i].num);
		}
		else
		{
			printf("%c", InfixExpression[i].oper);
		}

	}
	return SUCCESS;
}








//translate()�����Ķ��壬����;˵����Calculator.h��
void translate()
{
	//��׺���ʽת��Ϊ��׺���ʽ�������׺���ʽ����
	//iΪ��׺���ʽ�����±꣬jΪ��׺���ʽ�����±�
	for (size_t i = 0, j = 0; i < SIZE; ++i)
	{
		//���������� ������ջ
		if (InfixExpression[i].IsNum)
		{
			PostfixExpression[j].IsNum = SUCCESS;
			PostfixExpression[j++].num = InfixExpression[i].num;
		}
		//����ǰ��׺Ԫ�ز������֣����ж��Ƿ���Ҫ���룬i j ��ͬ��

		else
		{
			switch (InfixExpression[i].oper)
			{
			case '(':
				IsLeft();  
				break;
			case ')':
				IsRight(&j); //j���ܻᷢ���仯������ַ
				break;
			case '+':
				IsAdd(&j);  
				break;
			case '-':
				IsSub(&j);  
				break;
			case '*':
				IsMulti();  //���ȼ���
				break;
			case '/':
				IsDiv();  //��ǰԪ��Ϊ'/'ʱ����IsDiv()����Ϊ'/'ֱ����ջ������j���ᷢ���仯������Ҫ����
				break;
			case '=':   
				IsEqual(&j);
				return;
			}
		}
	}
}



//ֱ��push
void IsLeft()
{
	pushOper('(');
}

//�����')'�򵯳�ջ��Ԫ��ֱ��ջ��Ԫ��Ϊ'('����ջ��Ԫ��Ϊ'('ʱ����������
void IsRight(size_t* j)
{
	char oper;
	//�������ȷ�ı��ʽ��������)ʱջ��һ����(
	while (topOper > 0)
	{
		//��ȡջ��Ԫ��
		oper = popOper();

		//�����'('�򷵻�
		if (oper == '(')
			return;
		//�������'('�򽫸ò����������������׺���ʽ
		else
		{
			PostfixExpression[(*j)].IsNum = ERROR;
			PostfixExpression[(*j)++].oper = oper;
		}
	}
}




void IsAdd(size_t* j)
{
	char oper;
	while (topOper > 0)
	{
		oper = popOper();
		if (oper == '(')
		{
			pushOper(oper);
			break;
		}
		else
		{
			PostfixExpression[(*j)].IsNum = ERROR;
			PostfixExpression[(*j)++].oper = oper;
		}
	}

	pushOper('+');
}

void IsSub(size_t* j)
{
	char oper;
	while (topOper > 0)
	{
		oper = popOper();
		if (oper == '(')
		{
			pushOper(oper);
			break;
		}
		else
		{
			PostfixExpression[(*j)].IsNum = ERROR;
			PostfixExpression[(*j)++].oper = oper;
		}

	}

	pushOper('-');
}

void IsMulti()
{
	pushOper('*');
}

void IsDiv()
{
	pushOper('/');
}

void IsEqual(size_t* j)
{
	char oper;
	while (topOper > 0)
	{
		oper = popOper();
		PostfixExpression[(*j)].IsNum = ERROR;
		PostfixExpression[(*j)++].oper = oper;
	}
	PostfixExpression[(*j)].IsNum = ERROR;
	PostfixExpression[(*j)++].oper = '=';
}


double calculate()
{
	//���
	printf("��׺���ʽΪ��");
	for (size_t i = 0; i < SIZE; ++i)
	{
		if (!PostfixExpression[i].IsNum && PostfixExpression[i].oper == '=')
		{
			printf("%c\n", '=');
			break;
		}
		else if (PostfixExpression[i].IsNum)
		{
			printf("%d", PostfixExpression[i].num);
		}
		else
		{
			printf("%c", PostfixExpression[i].oper);
		}
	}
	//����
	for (size_t i = 0; i < SIZE; ++i)
	{
		
		if (PostfixExpression[i].oper == '=')
		{
			return popNum();
		}
		//������ջ
		else if (PostfixExpression[i].IsNum)
		{

			pushNum((double)(PostfixExpression[i].num));
		}
		
		//�Ƿ��� pop��ջ����Ԫ�ؽ��м��㲢���������ѹ��ջ
		else
		{
			//temp�����ݴ�ջ����Ԫ�صļ�����
			double temp = 0.0;
			//ע�⣬��һ��pop�Ҳ��������ڶ���popN�������
			double rear = popNum();
			double front = popNum();

			//���ݵ�ǰԪ��ѡ��Ӧ���е����㣬���������ջ
			switch (PostfixExpression[i].oper)
			{
			case '+':
				temp = front + rear;
				pushNum(temp);
				break;
			case '-':
				temp = front - rear;
				pushNum(temp);
				break;
			case '*':
				temp = front * rear;
				pushNum(temp);
				break;
			case '/':
				temp = front / rear;
				pushNum(temp);
				break;
			}
		}
	}

	return 0;
}