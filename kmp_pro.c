#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>


void get_nextval(const char* T,int *nextval)
{   
    int i,j;
    i=1;
    j=0;
    nextval[1] = 0;
    while(i<T[0])
    {
        if (j == 0 || T[i] == T[j])
        {
           ++i;
           ++j;
           if (T[i] != T[j])
           {
               nextval[i] = j;
           }else{
               nextval[i] = nextval[j];
           }
        }else{
            j = nextval[j];
        }
    }
}


int Index(char* S,char* T)
{
    int i=1;
    int j=1;
    int next[255]={0};
    get_nextval(T,next);

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
    
    char T[20]={0};
    int next[255]={0};

    T[0]=9;
    strcpy(&T[1],"ababaaaba");

    get_nextval(T,next);


    for (int i=1;i<10;i++)
    {
        printf("%d ",next[i]);
    }
    printf("\n");


    return 0;
}