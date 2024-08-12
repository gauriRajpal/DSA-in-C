#include<stdio.h>
#include<stdlib.h>
#define s 20

int main(){
    int a[s],n,i,j,min,temp;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    printf("Enter the elements of the array:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(a[min]>a[j])
                min=j;
        }
        if(min!=i){
            temp = a[min];
            a[min]= a[i];
            a[i]=temp;
        }
    }
    printf("The array in the sorted manner is:\n");
    for(i=0;i<n;i++){
        printf("%d",a[i]);
        printf("\n");
    }
}