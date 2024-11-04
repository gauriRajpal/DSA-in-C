#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

int sum(int);

int main(){
    int x,z;
    printf("Enter the number for which you want to find sum:\n");
    scanf("%d",&x);
    z=sum(x);
    printf("The sum is:%d\n",z);
}

int sum(int x){
    int s=0;
    if(x==0)
        return 0;
    s=x+sum(x-1);
    return s;
}