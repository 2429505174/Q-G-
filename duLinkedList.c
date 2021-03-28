#define _CRT_SECURE_NO_WARNINGS
#include "duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>
extern i_count;//�ڵ���    ȫ�ֱ���̫�� �д��Ż�
extern DuLNode* Findnode;
extern DuLNode* pEnd;
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList* L) {

    if (i_count == 0)
    {
        *L = (DuLinkedList)malloc(sizeof(DuLNode));//Ϊͷָ�뿪�ٿռ�
        if ((*L) == NULL)
        {
            printf("�ڴ����ʧ��\n");
            return ERROR;
        }
        (*L)->data = 0;
        (*L)->next = NULL;
        (*L)->prior = NULL;
    }
    DuLNode* p = (DuLinkedList)malloc(sizeof(DuLNode));
    //(*L)->next = p;
    if (NULL == p)
        return ERROR;
    printf("||-->����0����������\n");
    printf("||-->���������ݣ�");
    SCANF(&p->data);
   
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
            p->prior = *L;
            (*L)->next = p;
            (*L)->next = p;
            pEnd = p;
        }
        else {
            p->next = NULL;
            p->prior = pEnd;//���һ���ڵ���ͬ ��Ҫ���½ڵ�next ָ��null
            pEnd->next = p;//���¾ɽڵ���ϵ
            pEnd = p;//βָ�����
        }
        p = (DuLinkedList)malloc(sizeof(DuLNode));
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
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
    DuLinkedList temp;

    while (*L != NULL)
    {
        temp = *L;
        *L = (*L)->next;
        free(temp);
        i_count--;
    }
    i_count=0;
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
    if (p->data == 0)
        printf("||-->�޽ڵ㣡");
    else {
        q->next = p;         //�Ĳ��� �е��� ����ѧϰͳһһ��
        p->prior->next = q;
        q->prior = p->prior;
        p->prior = q;
        printf(printf("||-->����ɹ���\n"));
        i_count++;
    }

}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    if (p->next == NULL)//
    {
        p->next = q;
        q->prior = p;
    }
    else
    {
     
        q->next = p->next;  //�Ĳ��� �е��� ����ѧϰͳһһ��
        q->prior = p;
        p->next->prior = q;
        p->next = q;
        printf(printf("||-->����ɹ���\n"));
        return SUCCESS;
    }
    i_count++;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    if (p->next == NULL)
    {
        printf("||-->p���޽ڵ㣡\n");
        return ERROR;
    }
    else
    {
        DuLinkedList posNode = p->next, posNodeFront = p;
        
        if (posNode->next != NULL)
        {
            posNodeFront->next = posNode->next;//ǰ��ڵ�˫������
            posNode->next->prior = posNodeFront;
        }
        else
        {
            posNodeFront->next = NULL;
        }
        *e = posNode->data;
        free(posNode);
        printf("||-->ɾ���ɹ�\n");
        printf("||-->ɾ���ڵ��ڵ�data��%d\n", *e);
        return SUCCESS;
    }
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
    if (L == NULL)
    {
        printf("||-->��ͷָ�룡\n");
    }
    else if (L->next == NULL)
    {
        printf("||-->�޽ڵ㣡\n");
    }
    else
    {
        DuLinkedList temp = L->next;
        printf("||-->���������ݣ�");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

}


void Menu_hand()
{

    printf("*-----------------------------------------------*\n");
    printf("*\t\t0.exit\t\t\t\t*\n");
    printf("*\t\t1.InitList_DuL\t\t\t*\n");
    printf("*\t\t2.DestroyList_DuL\t\t*\n");
    printf("*\t\t3.InsertBeforeList_DuL\t\t*\n");
    printf("*\t\t4.InsertAfterList_DuL\t\t*\n");
    printf("*\t\t5.DeleteList_DuL\t\t*\n");
    printf("*\t\t6.TraverseList_DuL\t\t*\n");
    printf("||-->�����빦�ܲ˵���ţ�");
}

void visit(ElemType e) {

    printf("%d ", e);

}

void SCANF(ElemType* e) {

    int ret;
    ret = scanf("%d", e);
    while (ret != 1)
    {
        while (getchar() != '\n');
        //printf("||-->��Զ�����û���\n");
        printf("||-->��淶���룺");
        ret = scanf("%d", e);
    }

}

Status SearchList_DuL(DuLinkedList L, ElemType e) {
    while (L) {
        if (L->data == e)
        {
            Findnode = L;
            return SUCCESS;
        }
        L = L->next;
    }

    printf("||-->�޸ýڵ㣡\n");
    return ERROR;
}

DuLNode* creatNew() {
    DuLNode* New = (DuLNode*)malloc(sizeof(DuLNode));
    printf("||-->������New data��");
    SCANF(&New->data);
    New->next = NULL;
    New->prior = NULL;
    return New;
}