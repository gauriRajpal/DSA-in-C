#include<stdio.h>
#include<stdlib.h>
#define s 20

int main(){
    int a[s],n,i,j,x;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    printf("Enter the elements of the array:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                x=a[j];
                a[j]=a[j+1];
                a[j+1]=x;
            }
        }
    }
    printf("The array in sorted manner is:");
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
}