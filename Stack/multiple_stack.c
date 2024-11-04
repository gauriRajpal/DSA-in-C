#include<stdio.h>
#include<stdlib.h>
#define S 10

typedef struct Stack{
    int a[S];
    int top1,top2;
}stack;

void push(stack*,int,int);
int pop(stack*,int);
void dis(stack,int);

int main(){
    stack st;
    st.top1=-1;
    st.top2=S;
    int ch,id,x;
    printf("Menu-\n");
    do{
        printf("Enter the stack id-\n");
        scanf("%d",&id);
        printf("Enter the choice-\n1.Push OPeration\n2.Pop Operation\n3.Dispaly\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter the element to push-\n");
                    scanf("%d",&x);
                    push(&st,x,id);
                    break;
            case 2: x=pop(&st,id);
                    if(x!=-999)
                        printf("Popped element is %d\n",x);
                    break;
            case 3: printf("The elements are:\n");
                    dis(st,id);
                    break;
            case 4: exit(0);
            default:printf("Invalid input");
        }
    } while(1);
}

void push(stack*st,int x,int id){
    if(st->top1==st->top2-1){
        printf("Stack is full\n");
        return;
    }
    if(id==1){
        st->top1++;
        st->a[st->top1]=x;
    }
    else{
        st->top2--;
        st->a[st->top2]=x;
    }
}

int pop(stack*st,int id){
    int x;
    if(id==1){
        if(st->top1==-1){
            printf("Stack 1 is empty\n");
            return -999;
        }
        x=st->a[st->top1];
        st->top1--;
        return x;
    }
    if(id==2){
        if(st->top2==S){
            printf("Stack 2 is empty");
            return -999;
        }
        x=st->a[st->top2];
        st->top2++;
        return x;
    }
}

void dis(stack st,int id){
    int i;
    if(id==1){
        if(st.top1==-1){
            printf("Stack 1 is empty\n");
            return;
        }
        for(i=st.top1;i>=0;i--)
            printf("%d\n",st.a[i]);
    }
    if(id==2){
        if(st.top2==S){
            printf("Stack 2 is empty\n");
            return;
        }
        for(i=st.top2;i<=S;i++){
            printf("%d\n",st.a[i]);
        }
    }
}