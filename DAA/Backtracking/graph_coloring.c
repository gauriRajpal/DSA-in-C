#include<stdio.h>
#include<stdlib.h>

int x[10];
int g[10][10];
void adj(int,int);
void mcoloring(int,int,int);
void nextValue(int,int,int);

int main()
{
    int v,e,m;
    printf("Enter the number of vertices:\n");
    scanf("%d",&v);
    printf("Enter the number of edges:\n");
    scanf("%d",&e);
    adj(v,e);
    printf("Enter the number of colors:\n");
    scanf("%d",&m);
    for(int i=1;i<=v;i++)
        x[i]=0;
    mcoloring(1,v,m);
}


//CREATING ADJACENCY MATRIX 
void adj(int n,int m)
{
    int i,j,v1,v2;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            g[i][j]=0;
    for(i=1;i<=m;i++)
    {
        printf("Enter the vertices that are connected:\n");
        scanf("%d%d",&v1,&v2);
        g[v1][v2]=1;
        g[v2][v1]=1;
    }
}

//PASSING AND RETURING FUNCTION FOR GRAPH COLORING
void mcoloring(int k,int n,int m)
{
    do
    {
        nextValue(k,n,m);
        if(x[k]==0)
            return;
        if(k==n)
        {
            printf("Solution array:\n");
            for(int i=1;i<=n;i++)
                printf("%d",x[i]);
            printf("\n");
        }
        else
            mcoloring(k+1,n,m);
    }
    while(1);
}


//CHECKING IF WE CAN PUT 'M' COLORS OR NOT
void nextValue(int k,int n,int m)
{
    int j;
    do
    {
        x[k]=(x[k]+1)%(m+1);
        if(x[k]==0)
            return;
        for(j=1;j<=n;j++)
        {
            if((g[k][j]!=0)&&(x[k]==x[j]))
                break;
        }
        if(j==n+1)
            return;
    }
    while(1);
}