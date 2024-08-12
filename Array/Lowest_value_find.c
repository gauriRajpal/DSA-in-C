#include<stdio.h>
#include<stdlib.h>
#define s 20

int main(){
    int a[s],n,i,minVal;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    minVal=a[0];
    for(i=0;i<n;i++)
        if(a[i]<minVal)
            minVal = a[i];
    printf("The lowest value is:%d",minVal);
}