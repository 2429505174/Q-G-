#define _CRT_SECURE_NO_WARNINGS
#include "linkedList.h"
#include<stdio.h>
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)                        //ͷ���
 *	@return		 : Status
 *  @notice      : None
 */
extern i_count;
//extern LNode* L;//ͷβָ��
extern LNode* pEnd;
extern LNode* Pre ; 
extern int a, ret;
Status InitList(LinkedList* L) {
	
	//LinkedList* pp=L;
	if (i_count == 0)
	{
		*L = (LNode*)malloc(sizeof(LNode));//���ٽṹ������ڴ�;
		(*L)->data = 0;
	}
	 LNode* p= (LNode*)malloc(sizeof(LNode));
	 //(*L)->next = p;
	if (NULL == p)
		return ERROR;
	printf("||-->����0����������\n");
	printf("||-->���������ݣ�");
	SCANF(& p->data);
	/*while (ret != 1)
	{
		while (getchar() != '\n');
		ret = scanf("%d", &p->data);
	}*/
	if (p->data == 0)
	{
		free(p);
		return SUCCESS;
	}
	while (1)
	{
		i_count++;
		if (i_count == 1)
		{
			p->next = NULL;
			(*L)->next = p;
			pEnd = p;
		}
		else {
			p->next = NULL;  //���һ���ڵ���ͬ ��Ҫ���½ڵ�next ָ��null
			pEnd->next = p;//���¾ɽڵ���ϵ
			pEnd = p;//βָ�����
		}
		p = (LNode*)malloc(sizeof(LNode));
		if (NULL == p)
			return ERROR;
		printf("||-->���������ݣ�");
		SCANF(&p->data);
		if (p->data == 0)
			break;

	}
	free(p);
	return SUCCESS;
	//return pHead;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList* L) {
	printf("||-->����������data��");
	//ֻҪ�нڵ��ѭ�� ͷָ��һֱ����
	while ((*L)->next) {
		LNode* p = (*L)->next; //��ɾͷָ��
		/*Try()
		{
			*L = p->next;
		}
		catch (������)
		{
			printf("������");
		}*/

		(*L)->next = p->next;   //��ɾͷָ�� �ƶ�ͷָ��
		printf("%d ",p->data);
		free(p);
	}
	i_count = 0;
}
/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode* p, LNode* q) {
	LNode* pTemp =p->next;
	p->next = q;
	q->next = pTemp;
	i_count++;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode* p, ElemType* e) {
	if (p->next == NULL)
	{
		printf("||-->p���޽ڵ㣡\n");
		return ERROR;
	}
	LNode* pTemp = p->next;
	*e = (pTemp->data);
	p->next = pTemp->next;
	free(pTemp);
	printf("||-->ɾ���ڵ��ڵ�data��%d\n", *e);
	i_count--;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	LNode* p = L;
	if (p == NULL)
		printf("||-->�޽ڵ㣡\n");
	while (p) {
		visit(p->data);
		p = p->next;
	}

}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	int n = 0,t=0;
	LNode* temp[10] = { NULL };
	while (L) {
		if (L->data == e)
		{
			temp[n] = L;
			n++;
		}
		L = L->next;
	}
	if (n) {

		printf("||-->�ѷ���data��ͬ�Ľڵ�%d����\n",n);
		printf("||-->˳�����£�");
		n = 0;
		while (temp[n]) {
			printf("%d  ",temp[n]->data );
			n++;
			
		}

		printf("\n||-->��ѡ��ҪѰ�ҵڼ����ڵ㣺");
		SCANF(&t);
		while(t > n)
		{
			printf("||-->�������\n");
			printf("||-->��ѡ��ҪѰ�ҵڼ����ڵ㣺");
			SCANF( &t);
		}
		Pre = temp[t-1];
		return SUCCESS;
	}
	printf("||-->�޸ýڵ㣡\n");
	return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList* L) {

		LNode* tempHead=*L ;//���� ����ڵ㡱
		LNode* node=NULL;//���� ��ǰ�ڵ㡱
		while (1) {
			
			//node = tempHead->next;
			
			tempHead =(*L)->next;//�����ڵ���������
			if (tempHead->next == NULL)
				break;
			(*L)->next= tempHead->next;//ͷ��� ָ�� ���� ע�⣺��ָ��   ���ö�����ֹ��ַ��ʧ
			tempHead->next = node;//�����ڵ���������
			node = tempHead;//�����ڵ���������
			
		}
		tempHead->next = node;
		printf("||-->�ɹ�!\n");
		return SUCCESS;
	
	

}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	LNode* Knode=L;
	LNode* Mnode=L;

	while (Knode->next && Knode->next->next) {
		Mnode = Mnode->next;
		Knode = Knode->next->next;
		if (Mnode == Knode)
		{
			printf("||-->����ѭ����");
			return SUCCESS;
		}
	}
	printf("||-->������ѭ����");
	return ERROR;
}

void LoopList(LinkedList L) {
	pEnd->next = L;
}
void UnLoopList(LinkedList L) {
	pEnd->next =NULL;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList* L) {

	LNode* Head;
	LNode* node = (*L)->next;//���� ��ǰ�ڵ㡱
	LNode* node1 = node->next;//���� ����ڵ㡱
	LNode* node2 = (*L)->next;//������ 
	//Head1 = Head1->next;
	Head = node1; //ͷ�ڵ�ָ��2
	(*L)->next = Head;//ͷָ�벻�ܶ�
	while (node2&&node1) {
		node2= node1->next; //��ȡ�ú����ַ ������
		
		node1->next = node; //�ض� 
		if (!node2)
		{
			node->next = NULL;
			break;
		}
		node1 = node2->next;//��h1 �͵����汸��
		if (!node1)
		{
			node->next= node2;
			break;
		}
		node->next = node1;//����1 3 
		node = node2; //����node ����һ��������
	}
	printf("�ɹ�������\n");
	return Head;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList* L) {
	LNode* Knode = *L;
	LNode* Mnode =*L;

	while (Mnode) {
		if (!(Knode->next)) //����1���޽ڵ�  ����2���м����ж����������� �����Ǹ�Mnode ���Ʋ����Ƶ�����
			break;
		Mnode = Mnode->next;  


		if (!(Knode->next->next))
		{
			break;
		}
		Knode = Knode->next->next;

	}

	return Mnode;
}


void Menu_hand()
{

	printf("*-----------------------------------------------*\n");
	printf("*\t\t0.exit\t\t\t\t*\n");
	printf("*\t\t1.InitList\t\t\t*\n");
	printf("*\t\t2.DestroyList\t\t\t*\n");
	printf("*\t\t3.InsertList\t\t\t*\n");
	printf("*\t\t4.DeleteList\t\t\t*\n");  
	printf("*\t\t5.TraverseList\t\t\t*\n");
	printf("*\t\t6.SearchList\t\t\t*\n");
	printf("*\t\t7.ReverseList\t\t\t*\n");
	printf("*\t\t8.LoopList\t\t\t*\n");
	printf("*\t\t9.UnLoopList\t\t\t*\n");
	printf("*\t\t10.IsLoopList\t\t\t*\n");
	printf("*\t\t11.ReverseEvenList\t\t*\n");
	printf("*\t\t12.FindMidNode\t\t\t*\n");
	printf("||-->�����빦�ܲ˵���ţ�");
}
//����
//void FindPre(LinkedList L,int Index) {
//	while (L) {
//		if (L->data == )
//			return SUCCESS;
//		L = L->next;
//	}
//}
LNode* creatNew() {
	LNode* New = (LNode*)malloc(sizeof(LNode));
	printf("||-->������New data��");
	SCANF(&New->data);
	New->next = NULL;
	return New;
}
void visit(ElemType e) {

	printf("%d ", e);

}
void SCANF(ElemType* e) {
	
	int ret;
		ret = scanf("%d",e);
		getchar();
		while (ret != 1)
		{
			while (getchar() != '\n');
			//printf("||-->��Զ�����û���\n");
			printf("||-->��淶���룺");
			ret = scanf("%d", e);
		}
	
}