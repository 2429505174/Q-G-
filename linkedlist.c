#define _CRT_SECURE_NO_WARNINGS
#include "linkedList.h"
#include<stdio.h>
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)                        //头结点
 *	@return		 : Status
 *  @notice      : None
 */
extern i_count;
//extern LNode* L;//头尾指针
extern LNode* pEnd;
extern LNode* Pre ; 
extern int a, ret;
Status InitList(LinkedList* L) {
	
	//LinkedList* pp=L;
	if (i_count == 0)
	{
		*L = (LNode*)malloc(sizeof(LNode));//开辟结构体变量内存;
		(*L)->data = 0;
	}
	 LNode* p= (LNode*)malloc(sizeof(LNode));
	 //(*L)->next = p;
	if (NULL == p)
		return ERROR;
	printf("||-->输入0结束创建！\n");
	printf("||-->请输入数据：");
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
			p->next = NULL;  //与第一个节点相同 需要将新节点next 指向null
			pEnd->next = p;//将新旧节点搭建关系
			pEnd = p;//尾指针更新
		}
		p = (LNode*)malloc(sizeof(LNode));
		if (NULL == p)
			return ERROR;
		printf("||-->请输入数据：");
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
	printf("||-->链表内所有data：");
	//只要有节点就循环 头指针一直存在
	while ((*L)->next) {
		LNode* p = (*L)->next; //不删头指针
		/*Try()
		{
			*L = p->next;
		}
		catch (空链表)
		{
			printf("空链表");
		}*/

		(*L)->next = p->next;   //不删头指针 移动头指针
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
		printf("||-->p后无节点！\n");
		return ERROR;
	}
	LNode* pTemp = p->next;
	*e = (pTemp->data);
	p->next = pTemp->next;
	free(pTemp);
	printf("||-->删除节点内的data：%d\n", *e);
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
		printf("||-->无节点！\n");
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

		printf("||-->已发现data相同的节点%d个：\n",n);
		printf("||-->顺序如下：");
		n = 0;
		while (temp[n]) {
			printf("%d  ",temp[n]->data );
			n++;
			
		}

		printf("\n||-->请选择要寻找第几个节点：");
		SCANF(&t);
		while(t > n)
		{
			printf("||-->输入错误！\n");
			printf("||-->请选择要寻找第几个节点：");
			SCANF( &t);
		}
		Pre = temp[t-1];
		return SUCCESS;
	}
	printf("||-->无该节点！\n");
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

		LNode* tempHead=*L ;//链接 “后节点”
		LNode* node=NULL;//链接 “前节点”
		while (1) {
			
			//node = tempHead->next;
			
			tempHead =(*L)->next;//两个节点作用链接
			if (tempHead->next == NULL)
				break;
			(*L)->next= tempHead->next;//头结点 指向 后移 注意：是指向   作用二：防止地址丢失
			tempHead->next = node;//两个节点作用链接
			node = tempHead;//两个节点作用链接
			
		}
		tempHead->next = node;
		printf("||-->成功!\n");
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
			printf("||-->存在循环！");
			return SUCCESS;
		}
	}
	printf("||-->不存在循环！");
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
	LNode* node = (*L)->next;//链接 “前节点”
	LNode* node1 = node->next;//链接 “后节点”
	LNode* node2 = (*L)->next;//防断裂 
	//Head1 = Head1->next;
	Head = node1; //头节点指向2
	(*L)->next = Head;//头指针不能丢
	while (node2&&node1) {
		node2= node1->next; //先取得后面地址 防断裂
		
		node1->next = node; //截断 
		if (!node2)
		{
			node->next = NULL;
			break;
		}
		node1 = node2->next;//将h1 送到后面备用
		if (!node1)
		{
			node->next= node2;
			break;
		}
		node->next = node1;//链接1 3 
		node = node2; //更新node 到下一个交换点
	}
	printf("成功交换！\n");
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
		if (!(Knode->next)) //作用1：无节点  作用2：中间结点判断是做还是右 下面那个Mnode 后移不后移的问题
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
	printf("||-->请输入功能菜单序号：");
}
//备用
//void FindPre(LinkedList L,int Index) {
//	while (L) {
//		if (L->data == )
//			return SUCCESS;
//		L = L->next;
//	}
//}
LNode* creatNew() {
	LNode* New = (LNode*)malloc(sizeof(LNode));
	printf("||-->请输入New data：");
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
			//printf("||-->永远信任用户！\n");
			printf("||-->请规范输入：");
			ret = scanf("%d", e);
		}
	
}