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
    Node *top;
    int count;
} LinkStack;

Status Init(LinkStack *s)
{
    s->top = NULL;
    s->count = 0;
    return OK;
}

bool Empty(LinkStack *s)
{
    if (s->top == NULL)
    {
        return true;
    }
    return false;
}

Status Push(LinkStack *s, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
    {
        return ERROR;
    }
    p->data = e;
    p->next = s->top;
    s->top = p;

    return OK;
}

Status Pop(LinkStack *s, ElemType *e)
{
    if (Empty(s))
    {
        return ERROR;
    }

    Node *p = s->top;
    *e = p->data;
    s->top = p->next;
    free(p);

    return OK;
}

int main(void)
{
    LinkStack s;

    Init(&s);

    Push(&s, 3);
    Push(&s, 2);
    Push(&s, 1);

    Status ret;
    ElemType e;

    ret = Pop(&s, &e);
    assert(ret == OK && e == 1);
    ret = Pop(&s, &e);
    assert(ret == OK && e == 2);
    ret = Pop(&s, &e);
    assert(ret == OK && e == 3);

    assert(Empty(&s) == true);

    return OK;
}