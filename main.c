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

//按序号查找
int















































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





