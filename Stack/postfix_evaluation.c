#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
# define s 10

typedef struct Stack{
    int a[s];
    int top;
}stack;

void push(stack*,int);
int pop(stack*);
int postfixeval(char[s]);
int calc(int,int,char);

int main(){
    char express[s];
    int x, ch;
    printf("Enter a valid postfix expression-\n");
    scanf("%s",express);
    ch = postfixeval(express);
    printf("Result-\n%d",ch);
}

void push(stack* st,int x){
    st->top++;
    st->a[st->top]=x;
}

int pop(stack*st){
    int x;
    x = st->a[st->top];
    st->top--;
    return x;
}

int postfixeval(char exp[s]){
    stack st;
    st.top=-1;
    int i,lopnd,ropnd,res;
    i=0;
    while(exp[i]!='\0'){
        if(isdigit(exp[i]))
            push(&st,exp[i]-48);
        else if(exp[i]=='*'||exp[i]=='/'||exp[i]=='+'||exp[i]=='-'){
            ropnd= pop(&st);
            lopnd=pop(&st);
            res = calc(lopnd,ropnd,exp[i]);
            push(&st,res);
        }
        else    
            printf("INVALID CHARACTER!!");
        i++;
    }
    return pop(&st);
}

int calc(int l,int r, char op){
    switch(op){
        case '+':   return l+r;
        case '-':   return l-r;
        case '*':   return l*r;
        case '/':   return l/r;
    }
}