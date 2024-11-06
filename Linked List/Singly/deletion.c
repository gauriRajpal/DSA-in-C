#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int x;
    struct Node*next;
}node;

node*createnode(int);
node*insert(node*,int);
node*del_start(node*);
node*del_end(node*);
node*del_value(node*,int);
node*del_pos(node*,int);
void display(node*);

int main(){
    node*start;
    start=NULL;
    int ch,x;
    printf("Menu-\n1.Insertion\n2.Deletion from starting\n3.Deletion from ending\n4.Deletion by value\n5.Deletion by position\n6.Display\n7.Exit\n");
    do{
        printf("Enter the choice from the menu-\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the value to insert:\n");
                    scanf("%d",&x);
                    start=insert(start,x);
                    break;
            case 2: start=del_start(start);
                    break;
            case 3: start=del_end(start);
                    break;
            case 4: printf("Enter the value to delete\n");
                    scanf("%d",&x);
                    start=del_value(start,x);
                    break;
            case 5: printf("Enter the position to delete\n");
                    scanf("%d",&x);
                    start=del_pos(start,x);
                    break;
            case 6: printf("The elements are:\n");
                    display(start);
                    break;
            case 7: exit(0);
            default:printf("INVALID CHOICE\n")
        }
    }while(1);
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

node*del_start(node*start){
    node*temp;
    if(start==NULL){
        printf("The list is empty\n");
        return start;
    }
    temp=start;
    start=start->next;
    free(temp);
    return start;
}

node*del_end(node*start){
    node*p,*temp;
    if(start==NULL){
        printf("The list is empty\n");
        return start;
    }
    p=start;
    while(p->next->next!=NULL){
        p=p->next;}
    temp=p->next;
    p->next=NULL;
    free(temp);
    return start;
}

node*del_value(node*start,int data){
    node*p,*temp;
    if(start==NULL){
        printf("The list is empty\n");
        return start;
    }
    else if(start->x==data){
        temp=start;
        start=start->next;
        free(temp);
        return start;
    }
    else{
        p=start;
        while(p->next!=NULL&&p->next->x!=data)
            p=p->next;
        if(p->next==NULL){
            printf("Element not found\n");
            return start;
        }
        else{
            temp=p->next;
            p->next=p->next->next;
            free(temp);
            return start;
        }
    }
}

node*del_pos(node*start,int pos){
    node*p,*temp;
    int i=1;
    if(start==NULL){
        printf("The list is empty\n");
        return start;
    }
    if(pos==1){
        temp=start;
        start=start->next;
        free(temp);
        return start;
    }
    p=start;
    while(p->next!=NULL&&i<pos-1){
        p=p->next;
        i++;
    }
    if(p->next==NULL){
        printf("INVALID POSITION\n");
        return start;
    }
    temp=p->next;
    p->next=p->next->next;
    free(temp);
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