#include<stdio.h>
#include<stdlib.h>
#define S 10

typedef struct Stack{
    int a[S];
    int top;
}stack;

void push(stack*,int);
int pop(stack*);
int decimal(int);

int main(){
    int x;
    printf("Enter a decimal number\n");
    scanf("%d",&x);
    decimal(x);
}

void push(stack *st,int x){
    st->top++;
    st->a[st->top]=x;
}

int pop(stack*st){
    int x;
    x=st->a[st->top];
    st->top--;
    return x;
}

int decimal(int x){
    stack st;
    st.top=-1;
    int rem;
    while(x!=0){
        rem=x%2;
        push(&st,rem);
        x=x/2;
    }
    while(st.top!=-1)
       printf("%d",pop(&st));
    printf("\n");
}