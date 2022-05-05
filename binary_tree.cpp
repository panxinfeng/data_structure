#include <stdio.h>
#include <stdlib.h>
#include <queue>

#define OK 0
#define FALSE -1

typedef int Elemtype;
typedef int Status;

typedef struct TNode{
    Elemtype data;
    struct TNode* lchild;
    struct TNode* rchild;
}TNode;

void preOrder(TNode *p)
{
    if ( p != NULL)
    {
        printf("%d ",p->data);
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void midOrder(TNode *p)
{
     if ( p != NULL )
    {
        midOrder(p->lchild);
        printf("%d ",p->data);
        midOrder(p->rchild);
    }
}

void lastOrder(TNode *p)
{
    if ( p != NULL )
    {
        lastOrder(p->lchild);
        lastOrder(p->rchild);
        printf("%d ",p->data);
    }
}


void layerOrder(TNode *root)
{
    std::queue<TNode*> Q;
    Q.push(root);

    TNode* p = NULL;
    while(!Q.empty())
    {
        p = Q.front();
        Q.pop();
        printf("%d ",p->data);
        if (p->lchild != NULL)
        {
            Q.push(p->lchild);
        }
        if (p->rchild != NULL)
        {
            Q.push(p->rchild);
        }
    }
}

int main(void)
{
    TNode root = {1,NULL,NULL};
    TNode n1={2,NULL,NULL};
    TNode n2={3,NULL,NULL};
    TNode n3={4,NULL,NULL};
    TNode n4={5,NULL,NULL};

    root.lchild=&n1;
    root.rchild=&n2;

    n1.lchild=&n3;
    n1.rchild=&n4;

    //preOrder(&root)
    //midOrder(&root);
    //lastOrder(&root);
    layerOrder(&root);

    return 0;
}