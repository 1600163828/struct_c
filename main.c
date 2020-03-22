

//#include <stdio.h>
//#include <stdlib.h>
//
//typedef int ElementType;
//typedef struct LNode *PtrToLNode;
//struct LNode {
//    ElementType Data;
//    PtrToLNode Next;
//};
//typedef PtrToLNode List;
//
//List Read(); /* 细节在此不表 */
//
//int Length( List L );
//
//int main()
//{
//    List L = Read();
//    printf("%d\n", Length(L));
//    return 0;
//}
//int Length( List L ){
//
//    int i=0;
//    while(L->Next!=NULL){
//        i++;
//    }
//    return i;
//}














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
//    Position Last; /* 保存线性表中最后一个元素的位置 */
//};
//
//
//List MakeEmpty();//创建并返回一个空的线性表；
//Position Find( List L, ElementType X );//返回线性表中X的位置。若找不到则返回ERROR；
//bool Insert( List L, ElementType X, Position P );//将X插入在位置P并返回true。若空间已满，则打印“FULL”并返回false；如果参数P指向非法位置，则打印“ILLEGAL POSITION”并返回false
//bool Delete( List L, Position P );//将位置P的元素删除并返回true。若参数P指向非法位置，则打印“POSITION P EMPTY”（其中P是参数值）并返回false
//
//List MakeEmpty(){//创建并返回一个空的线性表
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
//顺序栈
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


ElemType topElem;//出栈的元素
ElemType GetElem;//取到的栈顶元素

//*************************************************

//初始化
SeqStack *InitStack();

//判断栈是否为空
int Empty(SeqStack *s);

//判断栈是否为已满
int Full(SeqStack *s);

//入栈
int Push(SeqStack *s,ElemType x);

//出栈
ElemType Pop(SeqStack *s,ElemType *x);

//取栈顶元素
ElemType GetTop(SeqStack *s,ElemType *x);

//置栈为空
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
    //测试第二个仓库22333
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
//头插法
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


//尾插法建立单链表
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

//求表长
int Length_LinkList(LinkList H){
    LinkList p=H;
    int j=0;
    while(p->next!=NULL){
        p=p->next;
        j++;
    }
    return j;
}

//单链表的逆置
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
//单链表删除重复节点
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

//初始化链表
void Init_SeqList(SeqList **L) {
    *L = (SeqList *) malloc(sizeof(SeqList));//动态分配内存空间
    (*L)->length = 0;//初始大小为0
}

//插入数据，i为插入的位置
int Insert_SeqList(SeqList *L, int i, ElemType x) {
    int j;
    if (L->length == MAXSIZE - 1) {
        printf("表满");
        return OVERFLOW;
    }
    if (i < 1 || i > L->length + 1) {
        printf("位置错");
        return ERROR;
    }
    for (j = L->length; j > i; j--) {
        L->elem[j + 1] = L->elem[j];
    }
    L->elem[i] = x;
    L->length++;
    printf("插入成功");
    return TRUE;
}

//顺序表的删除
int Delete_SeqList(SeqList *L, int i, ElemType e) {
    int j;
    if (i < 1 || i > L->length + 1) {
        printf("不存在第%d个元素", i);
        return ERROR;
    }
    for (j = i; j <= L->length; j++)
        L->elem[j] = L->elem[j + 1];
    L->length--;
    return TRUE;
}

//按值查找
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
    printf("\n当前顺序表的数据为：   ");
    for (i = 1; i <= L->length; ++i) {
        printf("%d   ", L->elem[i]);
    }
}


void PrintMenu() {
    printf("                                  顺序表插入，删除，按值查找\n");
    printf("                   1.   插入数据\n");
    printf("                   2.   删除数据\n");
    printf("                   3.   按值查找数据\n");
    printf("                   4.   打印链表\n");

    printf("                   9999.   退出\n\n\n");

}

void input();


void DataInit(SeqList *l);

int Judge() {
    int result = 0;
    printf("\n输入9999返回上一级！\n");
    scanf("%d", &result);
    printf("%d", result);

    if (result == 9999) {
        return 9999;
    } else return result;

}

void input(SeqList *L) {
    int in, j, datas,datat;
    ElemType k = 0;//用来存储删除的值
    PrintMenu();
    printf("请输入序号：");
    scanf("%d", &in);
    system("cls");
    while (in != 'q')
        switch (in) {
            case 1://存入数据
            {
                system("cls");
                do {
                    PrintList(L);
                    printf("\n请输入要插入的数：\n");
                    scanf("%d", &datas);
                    printf("请输入要插入的位置：\n");
                    scanf("%d", &j);
                    Insert_SeqList(L, j, datas);
                    PrintList(L);
                } while (Judge() != 9999);
                system("cls");
                input(L);

            }
                break;


            case 2://删除数据
                do {
                    system("cls");
                    PrintList(L);
                    printf("请输入要删除的序号：  \n");
                    scanf("%d", &j);
                    Delete_SeqList(L, j, k);
                    PrintList(L);
                } while (Judge() != 9999);
                system("cls");
                input(L);
                break;

            case 3://按照值查找
                do {
                    system("cls");
                    PrintList(L);
                    printf("请输入要查找的值：  ");
//                    scanf("%d\n", &datat);
                    scanf("%d",&datat);
                    int t = Locatin_SeqList(L, datat);
                    printf("序号为  %d",t);
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
    //添加初始数据
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





