#include <stdio.h>
#include <stdlib.h>


/*
线性表顺序结构
优点：
1.随机存取快。
2.无须为表示元素间的逻辑关系而使用额外空间

缺点：
1.插入删除操作时间复杂度高。
2.对于元素数量动态变化的线性表，很难确定空间大小。
3.造成存储空间的碎片。
*/

#define OK 1
#define ERROR 0
#define true 1
#define false 0
#define MaxSize 10
typedef int ElemType;
typedef int Status;
typedef struct {
    ElemType data[MaxSize];
    int length;
}SqList;


Status GetElem(SqList L,int i,ElemType* e)
{
    if (i<1 || i>L.length)
    {
        return ERROR;
    }
    *e = L.data[i-1];
    return OK;
}

Status InsertElem(SqList *L,int i,ElemType e)
{
    if (L->length >= MaxSize)
    {
        return ERROR;
    }
    if (i < 1 || i > L->length+1)
    {
        return ERROR;
    }
    for (int j=L->length-1;j >= i-1;j--)
    {
        L->data[j+1] = L->data[j];
    }
    L->data[i-1] = e;
    L->length++;

    return OK;
}


Status DeleteElem(SqList *L,int i,ElemType* e)
{
    if (L->length < 1)
    {
        return ERROR;
    }
    if (i < 1 || i > L->length)
    {
        return ERROR;
    }

    *e = L->data[i-1];

    for (int j=i-1;j < L->length-1;j++)
    {
        L->data[j] = L->data[j+1];
    }
    L->length--;

    return OK;
}

void Print(SqList *L)
{
    for(int i=0;i<L->length;i++)
    {
        printf("%d ",L->data[i]);
    }
    printf("\n");
}



int main(){
    SqList L;
    InsertElem(&L,1,10);
    InsertElem(&L,2,100);
    InsertElem(&L,3,1000);
    InsertElem(&L,4,10000);
    InsertElem(&L,5,100000);

    Print(&L);

    ElemType e;
    DeleteElem(&L,1,&e);
    DeleteElem(&L,1,&e);
    Print(&L);

    return 0;
}