#include <stdio.h>
#include <stdlib.h>

/*
线性表链式结构优点：
1.当知道元素的前缀时，插入删除操作的时间复杂度为O(1)
2.动态增减空间，空间利用率高。

线性表链式结构缺点：
1.查找一个元素时间复杂度为O(n)
2.需要为元素间的逻辑关系分配额外的空间。
3.造成存储空间的碎片。
*/

#define OK 0
#define ERROR -1
#define true 1
#define false 0

typedef int Status;
typedef int ElemType;
typedef struct Node{
    ElemType data;
    struct Node* next;
}Node;

Status Init(Node** head)
{
    *head = (Node*)malloc(sizeof(Node));
    if (*head == NULL)
        return ERROR;
    (*head)->next=NULL;
    return OK;
}

Status Insert(Node* head,int i,ElemType e)
{
    Node* p=head;
    int j=1;
    while(j < i && p)
    {
        p=p->next;
        ++j;
    }
    if (!p || j > i)
    {
        return ERROR;
    }
    Node* q = (Node*)malloc(sizeof(Node));
    if (q == NULL)
        return ERROR;
    q->data = e;
    q->next = p->next;
    p->next = q;
    return OK;
}

Status Delete(Node* head,int i,ElemType *e)
{
    Node* p = head;
    int j=1;
    while(j < i && p->next)
    {
        p=p->next;
        ++j;
    }
    if (j > i || !(p->next))
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
    while(p)
    {
        Node* q = p;
        p=p->next;
        free(q);
    }
    head->next = NULL;
    return OK;
}


void Print(Node *head)
{
    Node *p = head->next;
    if (p == NULL)
    {
        printf("empty list!\n");
        return;
    }
    while(p != NULL)
    {
        if (p->next == NULL)
        {
            printf("%d",p->data);
        }else{
            printf("%d -> ",p->data);
        }
        p=p->next;
    }
    printf("\n");
}

int main()
{
    Node* head;
    Status ret;
    ret = Init(&head);
    if (ret == ERROR)
    {
        printf("list init failed\n");
        exit(-1);
    }
    Insert(head,1,10000);
    Insert(head,1,1000);
    Insert(head,1,100);
    Insert(head,1,10);
    Print(head);

    ElemType e;
    Delete(head,4,&e);
    Print(head);
    Delete(head,3,&e);
    Print(head);
    Delete(head,2,&e);
    Print(head);

    Destory(head);
    Print(head);

    return 0;
}