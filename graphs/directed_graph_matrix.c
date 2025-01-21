#include<stdio.h>

void adjMatrix(int,int);
void display(int [20][20],int);

int main()
{
    int m,n;
    printf("Enter the number of vertices:\n");
    scanf("%d",&m);
    printf("Enter the number of edges:\n");
    scanf("%d",&n);
    adjMatrix(m,n);
}

void adjMatrix(int m,int n)
{
    int a[20][20],i,j,w;
    for(i=1;i<=m;i++)
        for(j=1;j<=m;j++)
            a[i][j]=0;
    for(i=1;i<=n;i++)
    {
        printf("Enter the vertex which is directed from %d:\n",i);
        printf("If %d has 0 out degree enter '-1' :",i);
        scanf("%d",&j);
        while(j!=-1)
        {
            printf("Enter the weight of the vertex:\n");
            scanf("%d",&w);
            a[i][j]=w;
            printf("Enter the vertex which is directed from %d:\n",i);
            printf("If %d has 0 out degree enter '-1' :",i);
            scanf("%d",&j);
        }
    }
    display(a,m);
}

void display(int a[20][20],int m)
{
    int i,j;
    printf("Adjacency matrix is:\n");
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++)
            printf("%d  ",a[i][j]);
        printf("\n");
    }
}