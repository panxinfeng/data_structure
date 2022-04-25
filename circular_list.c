#include <stdio.h>
#include <stdlib.h>

/*
循环单链表与单链表唯一的区别在于判断结束的条件
单链表：p -> next != NULL
循环单链表：p->next != head

循环链表相比单链表，优势在于：可以从任意一结点开始遍历整个链表。
*/



#define OK 0
#define ERROR -1
#define true 1
#define false 0

typedef int ElemType;
typedef int Status;
typedef struct Node{
    ElemType data;
    struct Node* next;
}Node;

Status Init(Node** head)
{
    *head = (Node*)malloc(sizeof(Node));
    if (*head == NULL)
        return ERROR;
    (*head) -> next =(*head);
    return OK;
}

Status Insert(Node * head,int i,ElemType e)
{

    Node *p = head->next;
    int j = 2;
    if (i == 1)
    {
        p = head;
        goto DO;
    }
    while(j < i && p != head)
    {
        p = p->next;
        ++j;
    }
    if (j > i || p == head)
    {
        return ERROR;
    }
DO:  
    {
        Node* q = (Node*)malloc(sizeof(Node));
        if (q == NULL)
            return ERROR;
        q->data = e;
        q->next = p->next;
        p->next =q;
    }
    
    return OK;
}

Status Delete(Node* head,int i,ElemType *e)
{
    Node* p = head;
    int j=1;
    while(j < i && p->next != head)
    {
        p=p->next;
        ++j;
    }
    if (j > i || (p->next == head))
    {
        return ERROR;
    }
    Node* q=p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}

Status Destory(Node* head)
{
    Node *p = head->next;
    while(p ->next != head)
    {
        Node* q = p;
        p=p->next;
        free(q);
    }
    head->next = head;
    return OK;
}

void Print(Node *head)
{
    Node *p = head->next;
    if (p == head)
    {
        printf("empty list!\n");
        return;
    }
    printf("head:%d ",head);
    while(p != head)
    {
        if (p->next == head)
        {
            printf("[curr:%d,data:%d,next:%d]",p,p->data,p->next);
        }else{
            printf("[curr:%d,data:%d,next:%d] -> ",p,p->data,p->next);
        }
        p=p->next;
    }
    printf("\n");
}

int main(void)
{

    Node* head;
    Status ret;
    ret = Init(&head);
    if (ret == ERROR)
    {
        printf("list init failed\n");
        exit(-1);
    }
    Print(head);
    Insert(head,1,2);
    Print(head);
    Insert(head,2,3);
    Print(head);


    ElemType e;
    Delete(head,3,&e);
    Print(head);
    Delete(head,2,&e);
    Print(head);
    Delete(head,1,&e);
    Print(head);

    Destory(head);
    Print(head);

    return 0;
}