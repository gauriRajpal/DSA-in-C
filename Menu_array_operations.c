#include<stdio.h>
#include<stdlib.h>
#define s 20

int insertion(int[],int,int,int);
int deletionvalue(int[],int,int);
int deletionposition(int[],int,int);
int ls(int[],int,int);
int isfull(int[],int);
int isempty(int[],int);

int main(){
    int a[s],n,i,ch,x,y,z;
    char result;
    printf("\nMenu-\n1.Insertion operation\n2.Deletion operation from value\n3.Deletion operation from position\n4.Exit\n");
    printf("Enter the array size-");
    scanf("%d",&n);
    printf("Enter the elements in the array\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    do{
        printf("Enter the number from the menu-");
        scanf("%d",&x);
        switch(x){
            case 1: if(isfull(a,x)){
                        break;
                    }
                    else{
                        printf("Enter the element to be inserted and it's position:");
                        scanf("%d%d",&y,&ch);
                        ch--;
                        z=insertion(a,n,y,ch);
                        printf("Array after insertion:\n");
                        for(i=0;i<z;i++)
                            printf("%d\n",a[i]);
                    }
                    break;
            case 2: if(isempty(a,n))
                        break;
                    else{
                        printf("Enter the value to be deleted:");
                        scanf("%d",&y);
                        z=deletionvalue(a,n,y);
                        printf("Array after deletion:\n");
                        for(i=0;i<z;i++)
                            printf("%d\n",a[i]);
                        }
                    break;
            case 3: if(isempty(a,n))
                        break;
                    else{
                        printf("Enter the position to delete from\n ");
                        scanf("%d",&ch);
                        z = deletionposition(a,n,ch);
                        printf("The array after deletion:\n");
                        for(i=0;i<z;i++)
                            printf("%d\n",a[i]);
                    }
                    break;
            case 4: exit(0);
            default: printf("Invalid choice! Enter the number from the menu.");
        }
        printf("\nDO YOU WAN TO CONTINUE?\n     Y OR NO?\n =");
        fflush(stdin);
        scanf("%c",&result);
    }
    while(result=='Y'||result=='y');
}

int ls(int a[s],int n,int x){
    if(n==s){
        printf("The array is full ! Can't insert.");
        return 1;
    }
    return 0;
}


int isfull(int a[s],int n){
    if(n==s){
        printf("The array is full ! Can't insert.");
        return 1;
    }
    return 0;
}

int isempty(int a[s],int n){
    if(n==0){
        printf("The array is empty ! Can't delete");
        return 1;
    }
    return 0;
}

int insertion(int a[s],int n,int x,int y){
    int i;
    if(y>n){
        printf("Invalid position\n");
        return n;
    }
    else{
        for(i=n;i>=y;i--)
            a[i+1]=a[i];
    }
    a[y]=x;
    n++;
    return n;
}


int deletionvalue(int a[s],int x,int y){
    int i,p;
    p=ls(a,x,y);
    if(p==-1){
        printf("\nElement not found\n");
        return x;
    }
    for(i=p;i<x-1;i++)
        a[i]=a[i+1];
    x--;
    return x;
}


int deletionposition(int a[s],int n,int y){
    int i;
    y--;
    if(y>n){
        printf("Invalid position");
        return n;
    }
    else{
        for(i=y;i<n-1;i++)
            a[i]=a[i+1];
    n--;
    return n;
    }
}