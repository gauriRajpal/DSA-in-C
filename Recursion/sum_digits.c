#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int sum(int);

int main(){
    int x,n;
    printf("Enter the number of digits you want sum:\n");
    scanf("%d",&x);
    n=sum(x);
    printf("The sum is:%d\n",n);
}

int sum(int x){
    if(x==0)
        return 0;
    return (x%10)+sum(x/10);
}