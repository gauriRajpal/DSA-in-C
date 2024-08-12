#include<stdio.h>
#include<stdlib.h>
#define s 20

int main(){
    int a[s],n,i,j,temp;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<n-1;i++){
        temp = a[i];
        for(j=i-1;j>=0 && a[j]>temp;j--)
            a[j+1] = a[j];
        a[j+1] = temp;
    }
    printf("The elements in the sorted array is:\n");
    for(i=0;i<n;i++)
        printf("%d",a[i]);
        printf("\n");
}