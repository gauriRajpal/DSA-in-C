#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int x;
    struct Node* next;
}node;

node*createnode(int);
node*insert(node*,int);
void display(node*);

int main(){
    node*start;
    start=NULL;
    int x,ch;
   do{
     printf("Enter the value you want to insert:\n");
    scanf("%d",&x);
    start=insert(start,x);
    printf("Do you want to continue:\n1 for YES and 2 for NO:\n");
    scanf("%d",&ch);
    }
while (ch==1);
    printf("The elements are:\n");
    display(start);
}

node*createnode(int data){
    node*nn;
    nn=(node*)malloc(sizeof(node));
    if(nn!=NULL){
        nn->x=data;
        nn->next=NULL;
    }
    return nn;
}

node*insert(node*start,int x){
    node*nn,*p;
    nn=createnode(x);
    if(start==NULL){
        start=nn;
        return start;
    }
    if(start->x>nn->x){
        nn->next=start;
        start=nn;
        return start;
    }
    p=start;
    while((p->next!=NULL)&&(p->next->x)<(nn->x))
        p=p->next;
    nn->next=p->next;
    p->next=nn;
    return start;
}

void display(node*start){
    node*p;
    if(start==NULL){
        printf("List is empty\n");
        return;
    }
    p=start;
    while(p!=NULL){
        printf("%d\n",p->x);
        p=p->next;
    }
}