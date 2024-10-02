#include<stdio.h>
#include<stdlib.h>
#define s 10

typedef struct Stack{
    int a[s];
    int top;
}stack;

void push(stack*,char);
char pop(stack*);
int isParenthesis_match(char[]);

int main(){
    char expr[s];
    printf("Enter any expression\n");
    scanf("%s",expr);
    if(isParenthesis_match(expr))
        printf("Balanced expression\n");
    else
        printf("Unbalanced expression\n");
}

void push(stack* st,char x){
    if(st->top==s-1){
        printf("Stack is full\n");
        return;
    }
    st->top++;
    st->a[st->top] = x;
}

char pop(stack*st){
    char x;
    if(st->top==-1){
        printf("Stack is empty\n");
        return '\0';
    }
    x=st->a[st->top];
    st->top--;
    return x;
}

int isParenthesis_match(char expr[s]){
    stack st;
    st.top=-1;
    int i=0;
    while(expr[i]!='\0'){
        if(expr[i]=='('||expr[i]=='{'||expr[i]=='[')
            push(&st,expr[i]);
        else {
            if(st.top!=-1&&((st.top=='('&&expr[i]==')')||(st.top=='['&&expr[i]==']')||(st.top=='{'&&expr[i]=='}'))){
               pop(&st); 
            }
            else
                return -999;
       }
       i++;
    }
    return 1;
}