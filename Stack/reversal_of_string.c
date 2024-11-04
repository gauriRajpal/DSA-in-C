#include<stdio.h>
#include<stdlib.h>
# define S 10

typedef struct Stack{
    char a[S];
    int top;
}stack;

void push(stack*,char);       
int pop(stack*);            
int reversal_string(char[]);

int main(){
    char expr[S];
    printf("Enter any expression:\n");
    scanf("%s",expr);
    reversal_string(expr);
    printf("Reversed expression is:%s\n",expr);
}

void push(stack*st,char x){
    st->top++;
    st->a[st->top]=x;
}

int pop(stack*st){
    char x;
    x=st->a[st->top];
    st->top--;
    return x;
}

int reversal_string(char str[]){
    stack st;
    st.top=-1;
    int i=0;
    while(str[i]!='\0'){
        push(&st,str[i]);
        i++;
    }
    i=0;
    while(st.top!=-1){
        str[i]=pop(&st);
        i++;
    }
    str[i]='\0';
}