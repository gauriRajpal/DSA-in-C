#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define s 10

typedef struct Stack{
    int a[s];
    int top;
}stack;

void push(stack*,int);
int pop(stack*);
int calc(int,int,char);
int prefix(char[s]);

int main(){
    int res;
    char expr[s];
    printf("Enter a valid prefix expression-\n");
    scanf("%s",expr);
    res = prefix(expr);
    printf("The result is-\n%d",res);
}

void push(stack* st,int x){
    st->top++;
    st->a[st->top]=x;
}

int pop(stack* st){
    int x;
    x=st->a[st->top];
    st->top--;
    return x;
}

int calc(int l,int r,char op){
    switch (op){
        case '+': return l+r;
        case '-':return l-r;
        case '*':return l*r;
        case '/':return l/r;
    }
}

int prefix(char expr[s]){
    stack st;
    st.top=-1;
    int lopnd,ropnd,res,i,l;
    l=strlen(expr);
    for(i=l-1;i>=0;i--){
        if(isdigit(expr[i]))
            push(&st,expr[i]-48);
        else if(expr[i]=='*'||expr[i]=='+'||expr[i]=='-'||expr[i]=='/'){
            lopnd=pop(&st);
            ropnd = pop(&st);
            res = calc(lopnd,ropnd,expr[i]);
            push(&st,res);
        }
        else{
            printf("INVALID");
            return -999;
        }
    }
    return pop(&st);
}