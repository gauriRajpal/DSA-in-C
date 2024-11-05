#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int x;
    struct Node* next;
}node;

node*createnode(int);
node*insert(node*,int,int);

int main(){
    node*start;
    start=NULL;
    int x,n;
    printf("Enter the value to insert:\n");
    scanf("%d",&x);
    printf("Enter the position at which you want to insert:\n");
    scanf("%d",&n);
    start=insert(start,x,n);
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

node*insert(node*start,int x,int pos){
    node*nn,*p;
    int c=1;
    p=start;
    nn=createnode(x);
    if(c!=pos-1){
        p=p->next;
        c++;
    }
    nn->next=p->next;
    p->next=nn;
    return start;
}