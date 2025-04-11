#include<stdio.h>
#include<stdlib.h>

int x[10];

void nqueen(int,int);
int place(int,int);

int main()
{
    int k=1,n;
    printf("\t\tN-Queens\n\t\t-----------------");
    printf("Enter number of queens:\n");
    scanf("%d",&n);
    printf("Solution Array:\n");
    nqueen(k,n);
}

void nqueen(int k,int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        if(place(k,i)==1)
        {
            x[k]=i;
            if(k==n)
            {
                for(j=1;j<=n;j++)
                    printf("%d",x[j]);
                printf("\n");
            }
            else
                nqueen(k+1,n);
        }
    }
}

int place (int k,int i)
{
    int j;
    for(j=1;j<k;j++)
    {
        if((x[j]==i)||(abs(x[j]-i)==abs(j-k)))
            return 0;
    }
    return 1;
}