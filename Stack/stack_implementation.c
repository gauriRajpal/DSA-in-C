#include<stdio.h>
#include<stdlib.h>
#define Size 10

typedef struct Stack{
    int a[Size];
    int top;
}stack;

void push(stack*,int);
int pop(stack*);
int peek(stack);
void traverse(stack);

int main(){
    stack s;
    s.top=-1;
    int x,ch;
    do{
        printf("Menu\n1.PUSH Operation\n2.POP Operation\n3.PEEK Operation\n4.TRAVERSING Operation\n5.Exit\n");
        printf("Enter the choice from the menu:\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the element to push:\n");
                    scanf("%d",&x);
                    push(&s,x);
                    break;
            case 2: x=pop(&s);
                    printf("The deleted element is:%d\n",x);
                    break;
            case 3: x=peek(s);
                    if(x>=0)
                        printf("The element at top is:%d\n",x);
                    break;
            case 4: printf("The elements are:\n");
                    traverse(s);
                    break;
            case 5: exit(0);
            default: printf("Inavlid choice!");
        }
    }while(1);
}

void push(stack*s,int x){
    if(s->top==Size-1){
        printf("Stack is full\n");
        return;
    }
    s->a[++s->top]=x;
}

int pop(stack*s){
    int x;
    if(s->top==-1){
        printf("Stack is empty\n");
        return 0;
    }
    x=s->a[s->top];
    s->top--;
    return x;
}

int peek(stack s){
    if(s.top==-1){
        printf("Stack is empty\n");
        return -999;
    }
    return s.a[s.top];
}

void traverse(stack s){
    int i;
    if(s.top==-1)
        printf("Stack is empty\n");
    for(i=0;i<=s.top;i++)
        printf("%d\n",s.a[i]);
}