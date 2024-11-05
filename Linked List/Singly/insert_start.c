#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int x;
    struct Node * next;
}node;

node*createnode(int);
node*insert(node*);

int main(){
    node*start;
    start=NULL;
    start=insert(start);
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

node*insert(node*start){
    node*nn,*p;
    int x;
    printf("Enter the value you want to enter\n");
    scanf("%d",&x);
    nn=createnode(x);
    if(start==NULL){
        start=nn;
        return start;
    }
    nn->next=start;
    start=nn;
    return start;
}