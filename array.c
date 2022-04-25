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
*/

#define OK 1
#define ERROR 0
#define true 1
#define false 0
#define InitialSize 10
#define IncrementSize 5

typedef int ElemType;
typedef int Status;
typedef struct {
    ElemType *data;
    int len;
    int cap;
}SqList;

Status Init(SqList *L)
{
    L->data = (ElemType*)malloc(sizeof(ElemType)*InitialSize);
    if (L->data == NULL)
        return ERROR;
    L->len =0;
    L->cap =InitialSize;
    return OK;
}

Status GetElem(SqList L,int i,ElemType* e)
{
    if (i<1 || i>L.len)
    {
        return ERROR;
    }
    *e = L.data[i-1];
    return OK;
}

Status InsertElem(SqList *L,int i,ElemType e)
{
    if (L->len >= L->cap)
    {
        ElemType *tmp  = (ElemType*)realloc(L->data,sizeof(ElemType)*(L->cap+IncrementSize));
        if (tmp == NULL)
            return ERROR;
        printf("readlloc ok\n");
        L->data = tmp;
        L->cap += IncrementSize;
    }
    if (i < 1 || i > L->len+1)
    {
        return ERROR;
    }
    for (int j=L->len-1;j >= i-1;j--)
    {
        L->data[j+1] = L->data[j];
    }
    L->data[i-1] = e;
    L->len++;

    return OK;
}

Status DeleteElem(SqList *L,int i,ElemType* e)
{
    if (L->len < 1)
    {
        return ERROR;
    }
    if (i < 1 || i > L->len)
    {
        return ERROR;
    }

    *e = L->data[i-1];

    for (int j=i-1;j < L->len-1;j++)
    {
        L->data[j] = L->data[j+1];
    }
    L->len--;

    return OK;
}

void Print(SqList *L)
{
    if (L->len == 0)
    {
        printf("empty array!\n");
        return;
    }
    for(int i=0;i<L->len;i++)
    {
        if (i==0){
            printf("[ %d ",L->data[i]);
        }else if(i == L->len-1){
            printf("%d ]\n",L->data[i]);
        }else{
            printf("%d, ",L->data[i]);
        }
        
    }
}

void Destory(SqList *L)
{
    free(L->data);
    L->data = NULL;
    L->len = 0;
    L->cap = 0;
}

int main(){
    SqList L;
    Status ret=OK;
    Init(&L);

    for(int i=1;i<20;i++)
    {
        ret = InsertElem(&L,i,i*10);
        if (ret != OK)
        {
            printf("insert failed!\n");
            exit(-1);
        }
    }
    Print(&L);

    ElemType e;
    DeleteElem(&L,1,&e);
    DeleteElem(&L,1,&e);
    Print(&L);

    Destory(&L);
    Print(&L);

    return 0;
}