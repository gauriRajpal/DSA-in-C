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
    printf("Menu-\n");
    do{
        printf("\nEnter the choice-\n1.Enque Operation\n2.Deque Operation\n3.Display Operation\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the element to enter:\n");
                    scanf("%d",&x);
                    enque(&q,x);
                    break;
            case 2: x=deque(&q);
                    printf("Dequed element is:%d\n",x);
                    break;
            case 3: printf("The elements are:\n");
                    dis(q);
                    break;
            case 4:exit(0);
            default:printf("Inavlid choice");
        }
    }while(1);
}

void enque(queue*q,int x){
    if((q->f==0&&q->r==s-1)||q->f==q->r+1){
        printf("Queue is empty\n");
        return;
    }
    if(q->r=s-1)
        q->r=0;
    else    
        q->r++;
    if(q->r==-1)
        q->f=0;
    q->a[q->r]=x;
    return;
}

int deque(queue*q){
    int x;
    if(q->f==-1&&q->r==-1){
        printf("Queue is empty\n");
        return -999;
    }
    x=q->a[q->f];
    if(q->f==q->r)
        q->r=q->f=-1;
    q->f=(q->f+1)%s;
    return x;
}

void dis(queue q){
    do{
        printf("%d\n",q.a[q.f]);
        q.f=(q.f+1)%s;
    }
    while(q.f!=(q.r+1)%s);
}