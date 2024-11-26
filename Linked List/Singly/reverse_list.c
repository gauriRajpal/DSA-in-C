#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int x;
    struct Node *next;
}node;

void display(node*start){
    node*p;
    if(start==NULL){
        printf("List is empty\n");
        return;
    }
    p=start;
    while(p){
        printf("%d\n",p->x);
        p=p->next;
    }
}

//Reverse display of the list:-

void revd(node*start){
    if(start==NULL){
        printf("The list is empty\n");
        return;
    }
    revd(start->next);
    printf("%d\n",start->x);
}

//Reversal of the list:-

node* rev(node*start){
    node*p,*n,*c=start;
    p=NULL;
    while(c!=NULL){
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    return p;
}

int main(){
    node*start;
    start=NULL;
    int ch,x;
    printf("Menu-\n1.Display\n2.Reverse Display\n3.Reversal of the list\n4.Exit\n");
    do{
        printf("Enter the choice from the menu-\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("The elements are:\n");
                    display(start);
                    break;
            case 2: if(start==NULL)
                        printf("The lsit is empty\n");
                    else{
                        printf("The elements are:\n");
                        revd(start);
                    }
                    break;
            case 3: start=rev(start);
                    printf("The list is reversed\n");
                    break;
            case 4: exit(0);
        }
    }
    while(1);
}