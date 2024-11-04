#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void hanoi(int,char,char,char);

int main(){
    int x;
    char A,B,C;
    printf("Enter the number of dishes\n");
    scanf("%d",&x);
    hanoi(x,'A','B','C');
}

void hanoi(int n,char A,char B,char C){
    if(n==0)
        return;
    hanoi(n-1,A,C,B);
    printf("%c to %c\n",A,C);
    hanoi(n-1,B,A,C);
}