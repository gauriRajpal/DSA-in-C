#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define s 10
typedef struct Stack{
    char a[s];
    int top;
}stack;

void push(stack*,int);
int pop(stack*);
int isEmpty(stack);
int isOpt(char);
int precedence(char);
void infix_postfix(char[]);

int main(){
    char isexpr[s];
    printf("Enter a valid infix expression-\n");
    scanf("%s",isexpr);
    infix_postfix(isexpr);
}

int isEmpty(stack st){
    if(st.top==-1)
        return 1;
    else    
        return 0;
}

void push(stack *st,int x){
    if(st->top==s-1){
        printf("Stack is full\n");
        return;
    }
    st->top++;
    st->a[st->top] = x;
}

int pop(stack*st){
    int x;
    if(st->top==-1){
        printf("Stack is empty\n");
        return '\0';
    }
    x = st->a[st->top];
    st->top--;
    return x;
}

int precedence(char op){
    if(op=='*'||op=='/')
        return 2;
    else if(op=='+'||op=='-')
        return 1;
    else
        return 0;
}

int isOpt(char opt){
    if(opt=='*'||opt=='-'||opt=='+'||opt=='/')
        return 1;
    else
        return 0;
}

void infix_postfix(char inexpr[s]){
    stack st;
    st.top = -1;
    int i=0,j=0;
    char post[s];
    while(inexpr[i]!='\0'){
        if(isdigit(inexpr[i])||isalpha(inexpr[i]))
            post[j++]=inexpr[i];
        else if(isOpt(inexpr[i])){
            if(isEmpty(st))
                push(&st,inexpr[i]);
            else{
                while((st.top!=-1)&&(precedence(inexpr[i]))<=precedence(st.a[st.top]))
                    post[j++]=pop(&st);
                push(&st,inexpr[i]);
            }
        }
        else{
            printf("INVALID CHOICE!!");
            return;
        }
        i++;
    }
    while(st.top!=-1)
        post[j++] = pop(&st);
    post[j]='\0';
    printf("Postfix Expression is =\n%s",post);
}