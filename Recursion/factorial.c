#include<stdio.h>
#include<math.h>
#include<string.h>

int fact(int);

int main(){
    int x,z;
    printf("Enter the number to find factorial of:\n");
    scanf("%d",&x);
    z=fact(x);
    printf("The factorial is : %d\n",z);
}

int fact(int x){
    if((x==1)||(x==0))
        return 1;
    return x*fact(x-1);
}