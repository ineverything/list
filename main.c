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
	InitList(&L); //����ͷ������������ͷ���ȥ��һЩ����
	ElemType sea,e,choice; 
	LNode* midNode;
	
	LNode *p = createNode(1);
	LNode *q = createNode(2);
	LNode *r = createNode(3);
	LNode *s = createNode(4); 
	//�ȴ���һ��������ͷ����������� 
	InsertList(L, s);
	InsertList(L, r);
	InsertList(L, q);
	InsertList(L, p);
	//�������� 
	TraverseList(L,visit);
	
	printf("��ѡ����Ҫ���еĲ�����������Ӧ������\n"); 
	printf("1���ж������ǲ���ѭ������\n"); 
	printf("2�����������ж��Ƿ����ĳԪ��\n");
	printf("3����ת�����Ԫ��\n");
	printf("4������������żλԪ��\n");
	printf("5�������м��㣬������Ԫ��ֵ\n");
	printf("6��ɾ��ĳ�����㲢�ҷ���ɾ���ڵ�ֵ\n");
	printf("-1����������\n");
	while(1){

 	scanf("%d",&choice); 	
	switch(choice){
	case 1:if( IsLoopList(L) )
				printf("����һ��ѭ������\n"); 
			else
				printf("�ⲻ��һ��ѭ������\n"); 
			break;
	
	case 2:printf("������һ��Ԫ�أ�");
		   scanf("%d",&sea); 
		   SearchList(L, sea);
		   break;
		
	case 3:if(ReverseList(&L)){
			printf("�ɹ���ת");	
			TraverseList(L,visit);
		}
		else 
			printf("��תʧ��\n"); 
		break;
	
	case 4:printf("������żλԪ�غ�\n"); 
		L =  ReverseEvenList(&L);
		TraverseList(L,visit);
		break;
	
	case 5: midNode = FindMidNode(&L);
			printf("�м�����%d\n",midNode->data);
			break;

	case 6:if ( DeleteList(p,&e)){
				printf("ɾ���ɹ�ĳ������Ľ�㣬�����ɾ��������ֵ��%d\n",e);
				TraverseList(L,visit);
			}
			else
				printf("ɾ��ʧ��\n"); 
			break;
	default:printf("�����ʽ����"); 
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
		printf("�����ڴ�ʧ��"); 
	} 
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
} 


