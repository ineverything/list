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
 {  /*初始化一个线性表，头结点，							 
	L是一个二级指针，*L指向那个结构指针，对这个结构指针分配内存 ，变成结构变量 ，可以访问里面的参数 
	LinkedList即*L是一个头指针，指向头结点
	  */ 
	*L = (LinkedList)malloc(sizeof(LNode)); 
	if(!(*L)) {  //内存分配失败 
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
	p = (*L)->next;  //p指向第一个结点 ，头结点后面 
	while(p){   //没到表尾 ，不为NULL时 
		q = p->next;  //循环到下一个，依次去释放内存 
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
{  /* p后面插入一个结点q
	有头结点同样可以操作
	p和q不能为空					 */ 
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
{   /*删除*p后的第一个结点，返回其值给e 
    指向结点的地址不为空
	下一个结点的地址不为空 		*/ 
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
 {  /*遍历链表和输出对应的值 
 	从头结点的下一个开始遍历
	 由头指针开始后移*/
	LinkedList p = L->next;   
	printf("链表里的元素是:"); 
	while(p){  //p不是null时 ，没有到结尾 
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
{  /*根据给出的数字找到对应的节点
	就是看链表里由没有数字e*/ 
    if(L->next == NULL) 
		return ERROR;
	LNode *p = L->next;//还是从头指针的下一个开始 
	ElemType cnt = 0;
	while(p != NULL){ //从头到尾循环 
		if(p->data == e){ 
			cnt = 1;
			break;
		}
		p = p->next;
	}
	if(cnt)
		printf("在链表里找到了%d\n",e);
	else
		printf("没找到"); 
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
{ /*反转链表，已知头指针 
   从头指针后面开始，头指针指向最后的那个节点
   原来第一个指向空，第二个指向第一个，*/ 
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
Status IsLoopList(LinkedList L) {  //循环部分 
	if(L == NULL||L->next == NULL)
		return ERROR;
	LNode *fast, *slow;
	fast = slow = L;				//快慢指针在相同起点
	while(fast && fast->next){
		slow = slow->next;			//slow走一个结点
		fast = fast->next->next;	//fast走两个结点
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
	LNode *pre, *cur, *Next;		//定义前中后指针，用途和反转相似
	pre = (*L)->next;
	(*L)->next = pre->next;
	while(pre && pre->next){
		cur = pre->next;
		Next = cur->next;
		if(cur->next && cur->next->next){			//如果cur->next不存在，结点个数为偶数
			pre->next = cur->next->next;			//如果cur->next->next不存在，结点个数为奇数
		}else{										//如果都存在，遍历未结束
			pre->next = cur->next;
		}
		cur->next = pre;							//将偶数结点反转
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
LNode* FindMidNode(LinkedList *L) {    //快慢指针，一步两步 
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

