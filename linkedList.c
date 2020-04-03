#include "linkedList.h"
#include<stdio.h>
#include<stdlib.h>



/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L)
 {  /*��ʼ��һ�����Ա�ͷ��㣬							 
	L��һ������ָ�룬*Lָ���Ǹ��ṹָ�룬������ṹָ������ڴ� ����ɽṹ���� �����Է�������Ĳ��� 
	LinkedList��*L��һ��ͷָ�룬ָ��ͷ���
	  */ 
	*L = (LinkedList)malloc(sizeof(LNode)); 
	if(!(*L)) {  //�ڴ����ʧ�� 
		return OVERFLOW;
	}
	(*L)->next = NULL;   
	return SUCCESS; 
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) 
{
	LinkedList p,q;
	p = (*L)->next;  //pָ���һ����� ��ͷ������ 
	while(p){   //û����β ����ΪNULLʱ 
		q = p->next;  //ѭ������һ��������ȥ�ͷ��ڴ� 
		free(p);
		p = q;
	} 
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) 
{  /* p�������һ�����q
	��ͷ���ͬ�����Բ���
	p��q����Ϊ��					 */ 
	if(p == NULL||q == NULL) 
		return ERROR;
	q->next = p->next;
	p->next = q;
	return SUCCESS;	
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) 
{   /*ɾ��*p��ĵ�һ����㣬������ֵ��e 
    ָ����ĵ�ַ��Ϊ��
	��һ�����ĵ�ַ��Ϊ�� 		*/ 
	if(p == NULL||p->next == NULL)
		return ERROR;
	LNode*q = p->next;
	*e = q->data;
	p->next = q->next;
	free(q);
	return SUCCESS;

}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e))
 {  /*��������������Ӧ��ֵ 
 	��ͷ������һ����ʼ����
	 ��ͷָ�뿪ʼ����*/
	LinkedList p = L->next;   
	printf("�������Ԫ����:"); 
	while(p){  //p����nullʱ ��û�е���β 
		visit(p->data);
		p=p->next; 
	}
	printf("\n");
}
/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e)
{  /*���ݸ����������ҵ���Ӧ�Ľڵ�
	���ǿ���������û������e*/ 
    if(L->next == NULL) 
		return ERROR;
	LNode *p = L->next;//���Ǵ�ͷָ�����һ����ʼ 
	ElemType cnt = 0;
	while(p != NULL){ //��ͷ��βѭ�� 
		if(p->data == e){ 
			cnt = 1;
			break;
		}
		p = p->next;
	}
	if(cnt)
		printf("���������ҵ���%d\n",e);
	else
		printf("û�ҵ�"); 
	return SUCCESS;

}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : Non
 */
Status ReverseList(LinkedList *L) 
{ /*��ת������֪ͷָ�� 
   ��ͷָ����濪ʼ��ͷָ��ָ�������Ǹ��ڵ�
   ԭ����һ��ָ��գ��ڶ���ָ���һ����*/ 
	if((*L) == NULL)return ERROR;
	LNode*p,*q,*r;
	p = (*L)->next;
	(*L)->next = NULL;
	q = r = NULL;
	while(p){
		q = p->next;
		p->next = r;
		r = p;
		p = q;
	}
	(*L)->next = r;
	return SUCCESS;
}
/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {  //ѭ������ 
	if(L == NULL||L->next == NULL)
		return ERROR;
	LNode *fast, *slow;
	fast = slow = L;				//����ָ������ͬ���
	while(fast && fast->next){
		slow = slow->next;			//slow��һ�����
		fast = fast->next->next;	//fast���������
		if(slow == fast)
			return SUCCESS;
	}
	return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L)
{
	if((*L) == NULL && (*L)->next == NULL)
		return (*L);
	LNode *pre, *cur, *Next;		//����ǰ�к�ָ�룬��;�ͷ�ת����
	pre = (*L)->next;
	(*L)->next = pre->next;
	while(pre && pre->next){
		cur = pre->next;
		Next = cur->next;
		if(cur->next && cur->next->next){			//���cur->next�����ڣ�������Ϊż��
			pre->next = cur->next->next;			//���cur->next->next�����ڣ�������Ϊ����
		}else{										//��������ڣ�����δ����
			pre->next = cur->next;
		}
		cur->next = pre;							//��ż����㷴ת
		pre = Next;
	}
	return (*L);
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {    //����ָ�룬һ������ 
	int i = 0;
	int j = 0;
	LNode * current= NULL;
	LNode * middle = 0;
	
	current = middle = (*L)->next;
	while(current != NULL){
		if(i/2>j){
			j++;
			middle = middle->next;
		}
		i++;
		current = current->next;
	}	
	return middle;
}

