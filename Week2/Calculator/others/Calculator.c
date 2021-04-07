#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <ctype.h>  //isdigit����
#include "Calculator.h"



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


Elem InfixExpression[SIZE]; //��׺���ʽ
Elem PostfixExpression[SIZE];//��׺���ʽ



//������ջ ��׺ת��׺ʹ��
char StackOper[SIZE];
extern size_t topOper; //ָ��ջ������Ŀ�λ
     
void pushOper(char oper)
{
	StackOper[topOper++] = oper;
}
//������ջ��pop
char popOper()
{
	return StackOper[--topOper];
}




//������ջ �����׺���ʽʹ��
double StackNum[SIZE];
extern size_t topNum ;
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




//������׺���ʽ  �ȴ�ת�� ��Ҫ�ԣ������ַ�תΪ����   
Status GetUn()
{
	//���ڱ����û���������
	char input[SIZE * 10];

	
	//ͨ��fgets������ȡ�û����� stdin ����Ҫ����
	fgets(input, sizeof(input) / sizeof(char), stdin);
	int x = 0;
	while (input[x] != '\n')
	{
		x++;
	}
	input[x] = '=';
	//input[x+1] = '\n';
	
	

	//�������'n'�򷵻�ERROR
	if (input[0] == '0')
		return ERROR;
	
	int num = 0;
	//��������input���� ������׺���ʽ
	for (size_t i = 0, j = 0; i < SIZE * 10; i++)
	{
	
		if (isdigit(input[i]))
		{
			num = num * 10 + input[i] - '0';  //��ȡ����
		}
		

		//��Щ���� ���� �ַ�
		else//����δ���� ����ÿ���ַ���Ҫ����ǰ�������ֵ����
		{
			//����ǰ�ַ�Ϊ'='���ʾ���ʽ����
			if (input[i] == '=') //=ǰ�� Ҫô�ǣ�Ҫô������
			{
				//�����ʽ'='֮ǰ���Ǹ��ַ�����')'���Ȼ��һ�������ַ�  ��������==
				if (input[i - 1] != ')')
				{
					InfixExpression[j].IsNum = SUCCESS;
					InfixExpression[j++].num = num;  //�ȸ�ֵ��++
					num = 0;   //num���� 
				}
				else if(input[i - 1] == '=')
				{
					break;
				}
				//��'='������׺���ʽ���鲢������input[]�ı���
				InfixExpression[j].IsNum = ERROR;
				InfixExpression[j++].oper = '=';
				break;
			}
			
			else if (input[i] == '(') //��ǰһ���ǲ����� ��˲�������
			{
				InfixExpression[j].IsNum = ERROR;
				InfixExpression[j++].oper = '(';
			}

			//��ȥ�������������������������')'����ǰһ��Ϊ�����ַ����򴢴�����
			else if (isdigit(input[i - 1])) //��������� ���� ��  ���� �Ӽ��˳�
			{
				InfixExpression[j].IsNum = SUCCESS;
				InfixExpression[j++].num = num;
				num = 0;
				InfixExpression[j].IsNum = ERROR;
				InfixExpression[j++].oper = input[i];
			}




			//����������������������� 
			else if (input[i] == ')' && input[i - 1] == ')') //����
			{

				InfixExpression[j].IsNum = ERROR;
				InfixExpression[j++].oper = ')';

			}
			
			//  ����Ӽ��˳�  ��ǰ������ ���� ���� �����־��Ѵ��� �ң�������
			else{
				//��������� ����ļӼ��˳�
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
			printf(" %d ", InfixExpression[i].num);
		}
		else
		{
			printf("%c", InfixExpression[i].oper);
		}

	}
	return SUCCESS;
}






//��׺���ʽת��Ϊ��׺���ʽ�������׺���ʽ����
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
	pushOper('(');
}

void IsRight(size_t* j)
{
	char oper;
	//�������ȷ�ı��ʽ��������)ʱջ��һ����(

	while (topOper > 0)//��ֹ���ʽ�쳣
	{
		//��ȡջ��Ԫ��
		oper = popOper();

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
	while (topOper > 0)
	{
		oper = popOper();
		if (oper == '(') 
		{
			pushOper(oper); //ȡջ�������� �Ƚ� ���ù���
			break;
		}
		else //�����Ӻ� һ�㶼Ҫ��ջ ���ˣ�
		{
			PostfixExpression[(*j)].IsNum = ERROR;
			PostfixExpression[(*j)++].oper = oper;
		}
	}

	pushOper('+');//���ѼӺ���ջ
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



//�˳����ȼ��� ֱ����ס
void IsMulti(size_t* j)
{
	char oper;
	while (topOper > 0)
	{
		oper = popOper();
		if (oper != '*' && oper != '/')
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
	pushOper('*');
}

void IsDiv(size_t* j)
{
	char oper;
	while (topOper > 0)
	{
		oper = popOper();
		if (oper != '*' && oper != '/')
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

	pushOper('/');
}



//���� ���ջ
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




//��׺���ʽ�������  ʹ���˺�׺���ʽ���飨���ޣ��� �� �Լ�������ջ  �������ǡ�ɲ��ܴ�����
double Calculate()
{
	//���
	printf("||-->��׺���ʽΪ��");
	for (size_t i = 0; i < SIZE; ++i)
	{
		if (!PostfixExpression[i].IsNum && PostfixExpression[i].oper == '=')
		{
			printf("%c\n", '=');
			break;
		}
		else if (PostfixExpression[i].IsNum)
		{
			printf(" %d ", PostfixExpression[i].num);
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
			return popNum(); //ȡ�������
		}
		//������ջ 
		else if (PostfixExpression[i].IsNum)
		{

			pushNum((double)(PostfixExpression[i].num));
		}
		
		//�������� pop��ջ����Ԫ�ؽ��м��㲢���������ѹ��ջ
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