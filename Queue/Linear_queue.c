#include<stdio.h>
#include<stdlib.h>
#define s 10

typedef struct Queue{
    int a[s];
    int f,r;
}queue;

void enque(queue*,int);
int deque(queue*);
void dis(queue);

int main(){
    queue q;
    q.f=q.r=-1;
    int ch,x;
    printf("Menu\n");
    do{
        printf("\nEnter the choice-\n1.Enque Operation\n2.Deque Operation\n3.Display Operation\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the element to enter-\n");
                    scanf("%d",&x);
                    enque(&q,x);
                    break;
            case 2: x=deque(&q);
                    if(x!=-999)
                        printf("Dequeued element is-\n%d",x);
                    break;
            case 3: printf("The elements are:\n");
                    dis(q);
                    break;
            case 4: exit(0);
            default:printf("Invalid choice\n");
        }
    }while(1);
}

void enque(queue*q,int x){
    if(q->r==s-1){
        printf("Queue is full\n");
        return;
    }
    if(q->r==-1)
        q->f++;
    q->r++;
    q->a[q->r]=x;
}

int deque(queue*q){
    int x =-999;
    if(q->f==-1){
        printf("The queue is empty\n");
    }
    x=q->a[q->f];
    if(q->f==q->r)
        q->f=q->r=-1;
    q->f++;
    return x;
}

void dis(queue q){
    int i;
    if(q.f==-1){
        printf("The queue is empty\n");
        return;
    }
    for(i=q.f;i<=q.r;i++)
        printf("%d\n",q.a[i]);
}