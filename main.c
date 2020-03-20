#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* ϸ���ڴ˲��� */

int Length( List L );

int main()
{
    List L = Read();
    printf("%d\n", Length(L));
    return 0;
}
int Length( List L ){

    int i=0;
    while(L->Next!=NULL){
        i++;
    }
    return i;
}














//#include <stdio.h>
//#include <stdlib.h>
//
//struct ListNode {
//    int data;
//    struct ListNode *next;
//};
//
//struct ListNode *createlist();
//
//int main()
//{
//    struct ListNode *p, *head = NULL;
//
//    head = createlist();
//    for ( p = head; p != NULL; p = p->next )
//        printf("%d ", p->data);
//    printf("\n");
//
//    return 0;
//}
//
//struct ListNode *createlist(){
//
//
//    struct ListNode *p,*H=NULL;
//    H=(struct ListNode*)(malloc(sizeof(struct ListNode)));
//    H->next=NULL;
//    int x;
//    scanf("%d",&x);
//    while (x!=-1){
//        p=(struct ListNode*)(malloc(sizeof(struct ListNode)));
//        p->data=x;
//        p->next=H->next;
//        H->next=p;
//        scanf("%d",&x);
//    }
//    return H->next;
//
//}
//
//
//

















//
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAXSIZE 5
//#define ERROR -1
//typedef enum {false, true} bool;
//typedef int ElementType;
//typedef int Position;
//typedef struct LNode *List;
//struct LNode {
//    ElementType Data[MAXSIZE];
//    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
//};
//
//
//List MakeEmpty();//����������һ���յ����Ա�
//Position Find( List L, ElementType X );//�������Ա���X��λ�á����Ҳ����򷵻�ERROR��
//bool Insert( List L, ElementType X, Position P );//��X������λ��P������true�����ռ����������ӡ��FULL��������false���������Pָ��Ƿ�λ�ã����ӡ��ILLEGAL POSITION��������false
//bool Delete( List L, Position P );//��λ��P��Ԫ��ɾ��������true��������Pָ��Ƿ�λ�ã����ӡ��POSITION P EMPTY��������P�ǲ���ֵ��������false
//
//List MakeEmpty(){//����������һ���յ����Ա�
//    List L;
//    L=(List)malloc(sizeof(struct LNode));
//    L->Last=(-1);
//    return L;
//}
//
//Position Find( List L, ElementType X ){
//
//    if(L->Last==(-1)){
//        return ERROR;
//    } else{
//        int i=0;
//        while(L->Data[i] != X && i<MAXSIZE-1){
//            i++;
//        }
//        if(i==MAXSIZE-1 && L->Data[i] != X ){
//            return ERROR;
//        } else return i;
//
//    }
//}
//
//bool Insert( List L, ElementType X, Position P ){
//    if(P>=MAXSIZE-1){
//        printf("ILLEGAL POSITION");
//        return false;
//    }
//    if(L->Last==MAXSIZE-1){
//        printf("FULL");
//        return false;
//    }
//    for (int j = L->Last; j >= P; j--) {
//        L->Data[j+1]=L->Data[j];
//    }
//    L->Data[P]=X;
//    L->Last++;
//}
//
//bool Delete( List L, Position P ){
//    if(P>=MAXSIZE-1 || L->Last > MAXSIZE-1){
//        printf("POSITION %d EMPTY",P);
//        return false;
//    } else{
//        return true;
//    }
//
//}
//
//
//int main()
//{
//    List L;
//    ElementType X;
//    Position P;
//    int N;
//
//    L = MakeEmpty();
//    scanf("%d", &N);
//    while ( N-- ) {
//        scanf("%d", &X);
//        if ( Insert(L, X, 0)==false )
//            printf(" Insertion Error: %d is not in.\n", X);
//    }
//    scanf("%d", &N);
//    while ( N-- ) {
//        scanf("%d", &X);
//        P = Find(L, X);
//        if ( P == ERROR )
//            printf("Finding Error: %d is not in.\n", X);
//        else
//            printf("%d is at position %d.\n", X, P);
//    }
//    scanf("%d", &N);
//    while ( N-- ) {
//        scanf("%d", &P);
//        if ( Delete(L, P)==false )
//            printf(" Deletion Error.\n");
//        if ( Insert(L, 0, P)==false )
//            printf(" Insertion Error: 0 is not in.\n");
//    }
//    return 0;
//}




















/*
//˳��ջ
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
#define MAXSIZE 50
#define TRUE 1
#define FALSE 0
typedef struct {
    ElemType elem[MAXSIZE];
    int top;
}SeqStack;


ElemType topElem;//��ջ��Ԫ��
ElemType GetElem;//ȡ����ջ��Ԫ��

//*************************************************

//��ʼ��
SeqStack *InitStack();

//�ж�ջ�Ƿ�Ϊ��
int Empty(SeqStack *s);

//�ж�ջ�Ƿ�Ϊ����
int Full(SeqStack *s);

//��ջ
int Push(SeqStack *s,ElemType x);

//��ջ
ElemType Pop(SeqStack *s,ElemType *x);

//ȡջ��Ԫ��
ElemType GetTop(SeqStack *s,ElemType *x);

//��ջΪ��
void SetEmpty(SeqStack *s);

//*************************************************

SeqStack *InitStack(){
    SeqStack *s;
    s=(SeqStack *)malloc(sizeof(SeqStack));
    s->top=-1;
    return s;
}

int Empty(SeqStack *s){
    return s->top==-1?TRUE:FALSE;
}

int Full(SeqStack *s){
    return s->top==MAXSIZE-1?TRUE:FALSE;
}

int Push(SeqStack *s,ElemType x){
    if(Full(s)){
        return FALSE;
    } else{
        s->top++;
        s->elem[s->top]=x;
        return TRUE;
    }
}

ElemType Pop(SeqStack *s,ElemType *x){
    if(Empty(s)){
        return FALSE;
    } else{

        *x=s->elem[s->top];
        s->top--;
        return TRUE;
    }
}

ElemType GetTop(SeqStack *s,ElemType *x){

    if(Empty(s)){
        return FALSE;
    } else{
        *x=s->elem[s->top];
        return TRUE;
    }
}

void SetEmpty(SeqStack *s){
    s->top=-1;
    //���Եڶ����ֿ�22333
}


*/





/*
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct node {
    DataType data;
    struct node *next;
}LNode,*LinkList;

int main(){

    return 0;
}
//ͷ�巨
LinkList CreatList_Head(){
    LinkList H;
    LNode *p;
    H=(LinkList)malloc(sizeof(LinkList));
    H->next=NULL;
    int x;
    scanf("%d",&x);
    while (x!=0){
        p=(LinkList)malloc(sizeof(LNode));
        p->data=x;
        p->next=H->next;
        H->next=p;
        scanf("%d",&x);
    }
    return H;
}


//β�巨����������
LinkList Creat_Tail(){
    LinkList H;
    LNode *p,*t=H;
    H = (LinkList)malloc(sizeof(LinkList));
    H->next = NULL;
    int x;
    scanf("%d",&x);
    while(x != -1){
        p=(LinkList)malloc(sizeof(LinkList));
        p->data=x;
        t->next = p;
        t=p;
        scanf("%d",&x);
    }
    t->next=NULL;
}

//���
int Length_LinkList(LinkList H){
    LinkList p=H;
    int j=0;
    while(p->next!=NULL){
        p=p->next;
        j++;
    }
    return j;
}

//�����������
void Reverse(LinkList H){
    LNode *q,*p;
    p=H->next;
    H->next=NULL;
    while(p) {
        q=p;
        p=p->next;
        q->next=H->next;
        H->next=q;
    }
}
//������ɾ���ظ��ڵ�
void pur_LinkList(LinkList H){
    LNode *p,*q,*r;
    p=H->next;
    while (p!=NULL){
        q=p;
        while(q->next){
            if(q->next->data==p->data){
                r=q->next;
                q->next=r->next;
                free(r);
            } else q=q->next;
        }
        p=p->next;
    }
}

*/


/*
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 30
#define OVERFLOW 0
#define TRUE 1
#define ERROR 0
#define FALSE 0


typedef int ElemType;
typedef struct {
    ElemType elem[MAXSIZE];
    int length;
} SeqList;

//��ʼ������
void Init_SeqList(SeqList **L) {
    *L = (SeqList *) malloc(sizeof(SeqList));//��̬�����ڴ�ռ�
    (*L)->length = 0;//��ʼ��СΪ0
}

//�������ݣ�iΪ�����λ��
int Insert_SeqList(SeqList *L, int i, ElemType x) {
    int j;
    if (L->length == MAXSIZE - 1) {
        printf("����");
        return OVERFLOW;
    }
    if (i < 1 || i > L->length + 1) {
        printf("λ�ô�");
        return ERROR;
    }
    for (j = L->length; j > i; j--) {
        L->elem[j + 1] = L->elem[j];
    }
    L->elem[i] = x;
    L->length++;
    printf("����ɹ�");
    return TRUE;
}

//˳����ɾ��
int Delete_SeqList(SeqList *L, int i, ElemType e) {
    int j;
    if (i < 1 || i > L->length + 1) {
        printf("�����ڵ�%d��Ԫ��", i);
        return ERROR;
    }
    for (j = i; j <= L->length; j++)
        L->elem[j] = L->elem[j + 1];
    L->length--;
    return TRUE;
}

//��ֵ����
int Locatin_SeqList(SeqList *L, ElemType x) {
    int i = 1;
    while (i < L->length && L->elem[i] != x)
        i++;
    if (i > L->length){
        return FALSE;
    }
    return i;
}


void PrintList(SeqList *L) {

    int i;
    printf("\n��ǰ˳��������Ϊ��   ");
    for (i = 1; i <= L->length; ++i) {
        printf("%d   ", L->elem[i]);
    }
}


void PrintMenu() {
    printf("                                  ˳�����룬ɾ������ֵ����\n");
    printf("                   1.   ��������\n");
    printf("                   2.   ɾ������\n");
    printf("                   3.   ��ֵ��������\n");
    printf("                   4.   ��ӡ����\n");

    printf("                   9999.   �˳�\n\n\n");

}

void input();


void DataInit(SeqList *l);

int Judge() {
    int result = 0;
    printf("\n����9999������һ����\n");
    scanf("%d", &result);
    printf("%d", result);

    if (result == 9999) {
        return 9999;
    } else return result;

}

void input(SeqList *L) {
    int in, j, datas,datat;
    ElemType k = 0;//�����洢ɾ����ֵ
    PrintMenu();
    printf("��������ţ�");
    scanf("%d", &in);
    system("cls");
    while (in != 'q')
        switch (in) {
            case 1://��������
            {
                system("cls");
                do {
                    PrintList(L);
                    printf("\n������Ҫ���������\n");
                    scanf("%d", &datas);
                    printf("������Ҫ�����λ�ã�\n");
                    scanf("%d", &j);
                    Insert_SeqList(L, j, datas);
                    PrintList(L);
                } while (Judge() != 9999);
                system("cls");
                input(L);

            }
                break;


            case 2://ɾ������
                do {
                    system("cls");
                    PrintList(L);
                    printf("������Ҫɾ������ţ�  \n");
                    scanf("%d", &j);
                    Delete_SeqList(L, j, k);
                    PrintList(L);
                } while (Judge() != 9999);
                system("cls");
                input(L);
                break;

            case 3://����ֵ����
                do {
                    system("cls");
                    PrintList(L);
                    printf("������Ҫ���ҵ�ֵ��  ");
//                    scanf("%d\n", &datat);
                    scanf("%d",&datat);
                    int t = Locatin_SeqList(L, datat);
                    printf("���Ϊ  %d",t);
                    PrintList(L);
                } while ((Judge() != 9999));
                system("cls");
                input(L);
                break;
            case 4:
                system("cls");
                do {
                    PrintList(L);
                } while ((Judge() != 9999));
                system("cls");
                input(L);
                break;
            case 9999:
                exit(0);


        }
}


int main() {

    int a[10];
    SeqList *L;
    Init_SeqList(&L);
    //��ӳ�ʼ����
    DataInit(L);
    input(L);
    return 0;
}

void DataInit(SeqList *L) {
    int i;
    for (i = 1; i <= 10; ++i) {
        L->elem[i] = i;
        L->length++;
    }

}*/





