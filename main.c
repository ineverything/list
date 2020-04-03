#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*	// Status InitList(LinkedList *L);
 	//void DestroyList(LinkedList *L);
	 //Status InsertList(LNode *p, LNode *q);
	Status DeleteList(LNode *p, ElemType *e);
	//void TraverseList(LinkedList L, void (*visit)(ElemType e));
	
//	Status SearchList(LinkedList L, ElemType e);
//	Status ReverseList(LinkedList *L);
//	Status IsLoopList(LinkedList L);
	//LNode* ReverseEvenList(LinkedList *L);
	//LNode* FindMidNode(LinkedList *L);*/ 


void visit(ElemType e){
	printf("%d ",e);
}
LNode *createNode(ElemType data);

int main(int argc, char *argv[])
 {
 	LinkedList L; 
	InitList(&L); //带有头结点的链表，利用头结点去做一些事情
	ElemType sea,e,choice; 
	LNode* midNode;
	
	LNode *p = createNode(1);
	LNode *q = createNode(2);
	LNode *r = createNode(3);
	LNode *s = createNode(4); 
	//先创建一个链表，在头结点后面加入结点 
	InsertList(L, s);
	InsertList(L, r);
	InsertList(L, q);
	InsertList(L, p);
	//遍历链表 
	TraverseList(L,visit);
	
	printf("请选择你要进行的操作，输入相应的数字\n"); 
	printf("1：判断链表是不是循环链表\n"); 
	printf("2：查找链表，判断是否存在某元素\n");
	printf("3：逆转链表的元素\n");
	printf("4：交换链表奇偶位元素\n");
	printf("5：查找中间结点，并返回元素值\n");
	printf("6：删除某结点后结点并且返回删除节点值\n");
	printf("-1：结束操作\n");
	while(1){

 	scanf("%d",&choice); 	
	switch(choice){
	case 1:if( IsLoopList(L) )
				printf("这是一个循环链表\n"); 
			else
				printf("这不是一个循环链表\n"); 
			break;
	
	case 2:printf("请输入一个元素：");
		   scanf("%d",&sea); 
		   SearchList(L, sea);
		   break;
		
	case 3:if(ReverseList(&L)){
			printf("成功逆转");	
			TraverseList(L,visit);
		}
		else 
			printf("逆转失败\n"); 
		break;
	
	case 4:printf("交换奇偶位元素后\n"); 
		L =  ReverseEvenList(&L);
		TraverseList(L,visit);
		break;
	
	case 5: midNode = FindMidNode(&L);
			printf("中间结点是%d\n",midNode->data);
			break;

	case 6:if ( DeleteList(p,&e)){
				printf("删除成功某个结点后的结点，这个被删除结点里的值是%d\n",e);
				TraverseList(L,visit);
			}
			else
				printf("删除失败\n"); 
			break;
	default:printf("输入格式有误"); 
	}
		if(choice == -1)
			break;
	}
		
	DestroyList(&L);
	 return 0; 
}

LNode* createNode(ElemType data)
{	
	LNode *newNode = (LNode*)malloc(sizeof(LNode));
	if(newNode == NULL){
		printf("分配内存失败"); 
	} 
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
} 


