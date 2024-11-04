#include<stdio.h>
#include<math.h>
#include<string.h>

int fib(int);

int main(){
    int x,n;
    printf("Enter the number till which you want the sum of series:\n");
    scanf("%d",&x);
    n=fib(x);
    printf("The sum of the series is:%d\n",n);
}

int fib(int x){
    if(x==1)
        return 0;
    if(x==2)
        return 1;
    return fib(x-1)+fib(x-2)+1;
}