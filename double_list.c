#include <stdio.h>
#include <stdlib.h>



/*
双向循环链表是使用最多的链表，
被众多语言集成在标准库中。

双向链表相比单向链表增加灵活，可以从链表的两个方向进行查找、删除、插入数据。
*/

#define OK 0
#define ERROR -1
#define true 1
#define false 0

typedef int Status;
typedef int ElemType;
typedef struct Node{
    ElemType data;
    struct Node* prev;
    struct Node* next;
}Node,*DoubleLinkList;

Status Init(DoubleLinkList *L)
{
    *L = (DoubleLinkList)malloc(sizeof(Node));
    if (*L == NULL)
        return ERROR;
    (*L)->prev = (*L);
    (*L)->next = (*L);
    return OK;
}

Status PushBack(DoubleLinkList head,ElemType e)
{
    Node *p = (Node*)malloc(sizeof(Node));
    if (p == NULL)
        return ERROR;
    p->data = e;

    head->prev->next = p;
    p->prev = head->prev;
    p->next = head;
    head->prev = p;

    return OK;
}

Status PushFront(DoubleLinkList head,ElemType e)
{
    Node *p = (Node*)malloc(sizeof(Node));
    if (p == NULL)
        return ERROR;
    p->data = e;

    head->next->prev = p;
    p->next = head->next;
    p->prev = head;
    head->next = p;

    return OK;
}

Status PopBack(DoubleLinkList head,ElemType *e)
{
    if (head ->next == head)
        return ERROR;

    Node *p =head->prev;

    p->prev->next = p->next;
    p->next->prev = p->prev;

    *e = p->data;
    free(p);

    return OK;
}

Status PopFront(DoubleLinkList head,ElemType *e)
{
    if (head ->next == head)
        return ERROR;
    
    Node *p =head->next;

    p->prev->next = p->next;
    p->next->prev = p->prev;

    *e = p->data;
    free(p);

    return OK;
}

Status Insert(DoubleLinkList head,int i,ElemType e)
{
    Node *p = head->next;
    int j = 2;
    if (i == 1)
    {
        p=head;
        goto DO;
    }
    while(j < i && p != head)
    {
        ++j;
        p = p->next;
    }
    if (j > i || (p == head && i != 1))
    {
        return ERROR;
    }
DO:
    {
        Node *q = (Node*)malloc(sizeof(Node));
        if (q == NULL)
            return ERROR;
        q->data = e;
        p->next->prev = q;
        q->next = p->next;
        p->next = q;
        q->prev = p;
    }

    return OK;
}

Status Erase(DoubleLinkList head,int i,ElemType *e)
{
    Node *p = head->next;
    int j=1;
    while(j < i && p != head)
    {
        p = p->next;
        ++j;
    }
    if (j > i || p == head)
        return ERROR;

    *e = p->data;

    p->prev->next = p->next;
    p->next->prev = p->prev;

    return OK;
}


Status Destory(DoubleLinkList head)
{
    Node *p,*q;
    p = head->next;
    while(p != head)
    {
        q = p;
        p=p->next;
        free(q);
    }
    head->prev=head;
    head->next =head;
}

void Print(DoubleLinkList head)
{
    Node* p = head->next;
    if (p == head)
    {
        printf("empty list!\n");
        return ;
    }
    while(p != head)
    {
        if (p->next != head)
        {
            printf("[curr:%d,data:%d,prev:%d,next:%d]->",p,p->data,p->prev,p->next);
        }else{
            printf("[curr:%d,data:%d,prev:%d,next:%d]\n",p,p->data,p->prev,p->next);
        }
        p=p->next;
    }
}

int main(void)
{
    DoubleLinkList head;
    Status ret = OK;
    ret = Init(&head);
    if (ret != OK)
    {
        printf("init failed!\n");
        exit(-1);
    }
     printf("--------------test push-------------------\n");
    for (int i=1;i<=5;i++)
    {
        ret = PushFront(head,i*10);
        if (ret != OK)
        {
            printf("push front failed");
            exit(-1);
        }
    }
    Print(head);
    for (int i=1;i<=5;i++)
    {
        ret = PushBack(head,i*100);
        if (ret != OK)
        {
            printf("push front failed");
            exit(-1);
        }
    }
    Print(head);
     printf("--------------test pop-------------------\n");
    ElemType e;
    PopFront(head,&e);
    Print(head);
    PopBack(head,&e);
    Print(head);

    PopBack(head,&e);
    PopBack(head,&e);
    PopBack(head,&e);

    Print(head);
    printf("--------------test earse-------------------\n");

    Erase(head,5,&e);
    Print(head);
    Erase(head,1,&e);
    Print(head);
    Erase(head,2,&e);
    Print(head);
    Erase(head,1,&e);
    Print(head);

    printf("--------------test insert-------------------\n");
    Print(head);
    Insert(head,1,9);
    Print(head);
    Insert(head,3,11);
    Print(head);
    Insert(head,1,8);
    Print(head);

    Destory(head);
    Print(head);

    return 0;
}