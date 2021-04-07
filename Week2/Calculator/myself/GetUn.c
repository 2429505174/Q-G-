#include<stdio.h>           
#include<stdlib.h>
//#include "LinkStack.h"
#include "Calculator.h"

#define SIZE 1000
Elem InfixExpression[SIZE]; //��׺���ʽ
Elem PostfixExpression[SIZE];//��׺���ʽ
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
				else if (input[i - 1] == '=')
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
			else {
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