#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define OK 0
#define FALSE -1

typedef int Status;
typedef char Elemtype;

typedef enum{
    Link,
    Thread
}PointerTag;

typedef struct TNode{
    Elemtype data;
    struct TNode* lchild;
    struct TNode* rchild;
    PointerTag LTag;
    PointerTag RTag;
}TNode;

TNode* pre=NULL;

void Inthreading(TNode *p)
{
    if (p != NULL)
    {
        Inthreading(p->lchild);
        printf("%c \n",p->data);
        if (pre != NULL)
        {
            if (p->lchild == NULL)
            {
                p->LTag = Thread;
                p->lchild = pre;
            }
            if (pre->rchild == NULL)
            {
                pre->RTag = Thread;
                pre->rchild = p;
            }
        }
        pre = p;
        Inthreading(p->rchild);
    }
}


int main(void)
{
    TNode head = {'0',NULL,NULL};
    head.rchild=NULL;

    TNode n1={'A',NULL,NULL};
    TNode n2={'B',NULL,NULL};
    TNode n3={'C',NULL,NULL};
    TNode n4={'D',NULL,NULL};
    TNode n5={'E',NULL,NULL};
    TNode n6={'F',NULL,NULL};
    TNode n7={'G',NULL,NULL};
    TNode n8={'H',NULL,NULL};
    TNode n9={'I',NULL,NULL};
    TNode n10={'J',NULL,NULL};

    head.lchild = &n1;

    n1.lchild = &n2;
    n1.rchild = &n3;

    n2.lchild = &n4;
    n2.rchild = &n5;

    n3.lchild = &n6;
    n3.rchild = &n7;

    n4.lchild = &n8;
    n4.rchild = &n9;

    n5.lchild = &n10;
    
    Inthreading(&head);

    //InOrderTraverse_Thr(&head);
    return 0;
}