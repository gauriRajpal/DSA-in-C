#include<stdio.h>
#define s 10

int second(int a[s],int n);
int main()
{
    int n,a[s];
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    printf("Enter the elements of array:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("The second largest element is:\n%d",second(a,n));
}

int second(int a[s],int n)
{
    if(n<2)
        return -1;
    int max=a[0],max1=a[0],i;
    for(i=0;i<n;i++)
    {
        if(a[i]>max)
        {
            max1=max;
            max=a[i];
        }
        else if(a[i]>max1&&a[i]!=max)
            max1=a[i];
    }
    if(max1==max)
        return -1;
    return max1;
}