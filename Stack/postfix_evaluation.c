#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define Size 30

typedef struct Stack{
    int a[30];
    int top;
}stack;

void push(stack*,int);
int pop(stack*);
int postfixeval(char[Size]);
int calc(int,int,char);

int main(){
    int x,y;
    char exp[Size];
    printf("Enter valid postfix expression:\n");
    scanf("%s",exp);
    x=postfixeval(exp);
    printf("The result is:%d\n",x);
}
void push(stack* st,int x){
    if(st->top==Size-1){
        printf("The stack is full\n");
        return;
    }
    st->top++;
    st->a[st->top] = x;   
}
int pop(stack*st){
    int x;
    if(st->top==-1)
        printf("The stack is empty");
    x=st->a[st->top];
    st->top--;
    return x;
}
int postfixeval(char exp[Size]){
    stack st;
    st.top = -1;
    int i,lopnd,ropnd,res;
    i=0;
    while(exp[i]!='\0'){
        if(isdigit(exp[i]))
            push(&st,exp[i]-48);
        else if(exp[i]=='*'||exp[i]=='+'||exp[i]=='-'||exp[i]=='/'){
            ropnd=pop(&st);
            lopnd=pop(&st);
            res=calc(lopnd,ropnd,exp[i]);
            push(&st,res);
        }
        else    
            printf("INAVLID CHARACTER\n");
        i++;
    }
    return pop(&st);
}

int calc(int l,int r,char op){
    switch(op){
        case '+' :return l+r;
        case '-' : return l-r;
        case '*' : return l*r;
        case '/' : return l/r;
    }
    return -999;
}