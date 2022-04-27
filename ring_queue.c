#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>



#define OK 0
#define ERROR -1
#define MAXSIZE 5

typedef int Status;
typedef int ElemType;
typedef struct{
    ElemType data[MAXSIZE];
    int front;
    int rear;
}SqQueue;

Status Init(SqQueue *s)
{
    s->front = 0;
    s->rear = 0;
    return OK;
}

bool Empty(SqQueue *s)
{
    return s->front == s->rear;
}

bool Full(SqQueue *s)
{
    return (s->rear + 1)%MAXSIZE == s->front;
}

int GetLen(SqQueue *s)
{
    return (s->rear - s->front + MAXSIZE)%MAXSIZE;
}

Status GetHead(SqQueue *s,ElemType *e)
{
    if (Empty(s))
    {
        return ERROR;
    }
    *e = s->data[s->front];
    return OK;
}

Status EnQueue(SqQueue*s,ElemType e)
{
    if (Full(s))
    {
        return ERROR;
    }
    s->data[s->rear] = e;
    s->rear = (s->rear+1)%MAXSIZE;
    return OK;
}

Status DeQueue(SqQueue*s,ElemType *e)
{
    if (Empty(s))
    {
        return ERROR;
    }
    *e = s->data[s->front];
    s->front =(s->front+1)%MAXSIZE;
    return OK;
}

int main(void)
{
    SqQueue s;

    Init(&s);

    EnQueue(&s,1);
    EnQueue(&s,2);
    EnQueue(&s,3);
    EnQueue(&s,4);

    Status ret;
    ElemType e;
    ret = EnQueue(&s,1);
    assert(ret == ERROR);
    assert(Full(&s));

    ret = DeQueue(&s,&e);
    assert( ret == OK && e == 1);
    ret = DeQueue(&s,&e);
    assert( ret == OK && e == 2);
    ret = DeQueue(&s,&e);
    assert( ret == OK && e == 3);
    ret = DeQueue(&s,&e);
    assert( ret == OK && e == 4);
    ret = DeQueue(&s, &e);
    assert( ret == ERROR && e == 4);

    return 0;
}