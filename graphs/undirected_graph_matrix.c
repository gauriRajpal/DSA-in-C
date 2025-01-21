#include<stdio.h>

void adjMatrix(int ,int);
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
    int a[20][20],i,j,v1,v2;
    for(i=1;i<=m;i++)
        for(j=1;j<=m;j++)
            a[i][j]=0;
    for(i=1;i<=n;i++)
    {
        printf("Enter the edges which are connected:\n");
        scanf("%d%d",&v1,&v2);
        a[v1][v2]=1;
        a[v2][v1]=1;
    }
    display(a,m);
}

void display(int a[20][20],int m)
{
    int i,j;
    printf("Adjanecy matrix is:\n");
    for(i=1;i<=m;i++)
    {
         for(j=1;j<=m;j++)
                 printf("\t %d ",a[i][j]);
            printf("\n");
    }
}
