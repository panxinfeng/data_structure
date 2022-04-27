#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define OK 0
#define ERROR -1

typedef int ElemType;
typedef int Status;
typedef struct
{
    ElemType data;
    struct Node *next;
} Node;

typedef struct
{
    Node* front;
    Node* rear;
} LinkQueue;

Status Init(LinkQueue* Q)
{
    Q->front = Q->rear =NULL;
}

bool Empty(LinkQueue *Q)
{
    return Q->front ==NULL && Q->rear == NULL;
}

Status EnQueue(LinkQueue *Q ,ElemType e)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->next = NULL;

    if (Empty(Q))
    {
        Q->front = Q->rear = p;
        return OK;
    }
    Q->rear->next = p;
    Q->rear = p;
    return OK;
}

Status DeQueue(LinkQueue *Q,ElemType *e)
{
    if (Empty(Q))
    {
        return ERROR;
    }
    Node *p = Q->front;
    *e = p->data;
    if (Q->front == Q->rear)
    {
        Q->front = Q->rear = NULL;
    }else{
        Q->front= Q->front->next;
    }
    free(p);

    return OK;
}


void Destory(LinkQueue *Q)
{
    if (Empty(Q))
    {
        return;
    }
    Node* p = NULL;
    do{
        p = Q->front;
        Q->front = p->next;
        free(p); 
    }while(p != Q->rear);
    Q->front = Q->rear = NULL;
}


int main(void)
{
    LinkQueue Q;
    Status ret;
    Init(&Q);

    ret = EnQueue(&Q,1);
    assert(ret == OK);
    ret = EnQueue(&Q,2);
    assert(ret == OK);
    ret = EnQueue(&Q,3);
    assert(ret == OK);

    ElemType e;
   
    ret = DeQueue(&Q,&e);
    assert(ret == OK &&e == 1);
    ret = DeQueue(&Q,&e);
    assert(ret == OK &&e == 2);
    ret = DeQueue(&Q,&e);
    assert(ret == OK && e == 3);
    ret = DeQueue(&Q,&e);
    assert(ret == ERROR && e == 3);

    Destory(&Q);

    return 0;
}