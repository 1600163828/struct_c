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

//����Ų���
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





