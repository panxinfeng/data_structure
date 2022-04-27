#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define MaxSize 10
#define OK 0
#define ERROR -1

typedef int ElemType;
typedef int Status;
typedef struct
{
    ElemType data[MaxSize];
    int top;
} Stack;

Status Init(Stack *s)
{
    s->top = -1;
    return OK;
}

bool Empty(Stack *s)
{
    return s->top == -1;
}

Status Push(Stack *s, ElemType e)
{
    if (s->top >= MaxSize - 1)
    {
        return ERROR;
    }
    s->top++;
    s->data[s->top] = e;
    return OK;
}

Status Pop(Stack *s, ElemType *e)
{
    if (Empty(s))
    {
        return ERROR;
    }
    *e = s->data[s->top];
    s->top--;
    return OK;
}

int main(void)
{
    Stack s;
    Init(&s);
    Push(&s, 1);
    Push(&s, 2);
    Push(&s, 3);

    assert(Empty(&s) != true);

    ElemType e;
    Status ret;

    ret = Pop(&s, &e);
    assert(e == 3 && ret == OK);
    ret = Pop(&s, &e);
    assert(e == 2 && ret == OK);
    ret = Pop(&s, &e);
    assert(e == 1 && ret == OK);

    ret = Pop(&s, &e);
    assert(e == 1 && ret == ERROR);

    return 0;
}