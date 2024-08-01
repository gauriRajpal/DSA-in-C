#include<stdio.h>
#include<stdlib.h>

void add(int,int);
void sub(int,int);
void mult(int,int);
void divi(int,int);

int main(){
    int a,b, res;
    char user;
    printf("\nMenu-\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Exit\n");
    do{
        printf("Enter two numbers:");
        scanf("%d%d",&a,&b);
        printf("\nEnter the number of your choice:");
        scanf("%d",&res);
        switch(res)
        {
            case 1: add(a,b);
                    break;
            case 2: sub(a,b);
                    break;
            case 3: mult(a,b);
                    break;
            case 4: divi(a,b);
                    break;
            case 5: exit(0);
            default: printf("Invalid choice! Enter from the given numbers");
        }
        printf("DO YOU WANT TO CONTINUE?\n Y OR N?\n");
        fflush(stdin);
        scanf("%c",&user);
    }
    while(user=='y'||user=='Y');
}

void add(int x,int y){
    printf("The answer is:");
    printf("%d\n",x+y);
}

void sub(int x,int y){
    if(x>=y){
        printf("The answer is:");
        printf("%d\n",x-y);
    }
    else{
        printf("The answer is:");
        printf("%d\n",y-x);
    }
}


void mult(int x,int y){
    printf("The answer is:");
    printf("%d\n",x*y);
}


void divi(int x,int y){
    printf("The answer is:");
    printf("%d\n",x/y);
}