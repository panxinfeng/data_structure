#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define MaxSize 10
#define OK 0
#define ERROR -1
#define STACKLEFT 1
#define STACKRIGHT 2

typedef int ElemType;
typedef int Status;
typedef int StackType;
typedef struct
{
    ElemType data[MaxSize];
    int left;
    int right;
} Stack;

Status Init(Stack *s)
{
    s->left = -1;
    s->right = MaxSize;
    return OK;
}

bool Full(Stack *s)
{
    if (s->left + 1 == s->right)
    {
        return true;
    }
    return false;
}

bool Empty(Stack *s)
{
    if (s->left == -1 && s->right == MaxSize)
    {
        return true;
    }
    return false;
}

Status Push(Stack *s, StackType type, ElemType e)
{
    if (Full(s))
    {
        return ERROR;
    }
    if (type == STACKLEFT)
    {
        s->data[++(s->left)] = e;
    }
    else if (type == STACKRIGHT)
    {
        s->data[--(s->right)] = e;
    }
    else
    {
        return ERROR;
    }
    return OK;
}

Status Pop(Stack *s, StackType type, ElemType *e)
{
    if (Empty(s))
    {
        return ERROR;
    }
    if (type == STACKLEFT)
    {
        *e = s->data[s->left--];
    }
    else if (type == STACKRIGHT)
    {
        *e = s->data[s->right++];
    }
    else
    {
        return ERROR;
    }
    return OK;
}

int main(void)
{
    Stack s;
    Init(&s);

    Push(&s, STACKLEFT, 1);
    Push(&s, STACKLEFT, 2);
    Push(&s, STACKLEFT, 3);
    Push(&s, STACKLEFT, 4);
    Push(&s, STACKLEFT, 5);

    Push(&s, STACKRIGHT, 10);
    Push(&s, STACKRIGHT, 9);
    Push(&s, STACKRIGHT, 8);
    Push(&s, STACKRIGHT, 7);
    Push(&s, STACKRIGHT, 6);

    Status ret;
    ElemType e;

    assert(Full(&s));
    ret = Push(&s, STACKRIGHT, 11);
    assert(ret == ERROR);

    ret = Pop(&s, STACKLEFT, &e);
    assert(ret == OK && e == 5);
    ret = Pop(&s, STACKRIGHT, &e);
    assert(ret == OK && e == 6);

    return 0;
}