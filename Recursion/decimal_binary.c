#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int dtb(int);

int main(){
    int x,n;
    printf("Enter decimal number :\n");
    scanf("%d",&x);
    dtb(x);
}
int dtb(int x){
    if(x==0)
        return 0;
    dtb(x/2);
    printf("%d",x%2);
}