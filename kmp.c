#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>


void get_next(const char* T,int *next)
{   
    int i,j;
    i=1;
    j=0;
    next[1] = 0;
    while(i<T[0])
    {
        if (j == 0 || T[i] == T[j])
        {
           ++i;
           ++j;
           next[i] = j; 
        }else{
            j = next[j];
        }
    }
}


int Index(char* S,char* T)
{
    int i=1;
    int j=1;
    int next[255]={0};
    get_next(T,next);

    while(i <= S[0] && j <= T[0])
    {
        if (j==0 || S[i] == T[j])
        {
            i++;
            j++;
        }else{
            j = next[j];
        }
    }
    
    if (j > T[0])
    {
        return i-T[0];
    }else{
         return 0;
    }
}

int main()
{
    
    char T[7]={0};
    T[0]=5;
    strcpy(&T[1],"abcab");

    puts(&T[0]);

    int next[255]={0};
    get_next(T,next);

    for (int i=1;i<10;i++)
    {
        printf("%d ",next[i]);
    }
    printf("\n");

    char S[10]={0};
    S[0] = 8;
    strcpy(&S[1],"xyabcaba");
    int pos = Index(S,T);
    printf("pos = %d\n",pos);

    return 0;
}