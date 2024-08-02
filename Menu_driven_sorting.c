#include<stdio.h>
#include<stdlib.h>

void bubblesort(int[],int);
void selectionsort(int[],int);
void insertionsort(int[],int);
void display(int[],int);


int main(){
    int a[20],n,x;
    char result;
    printf("Enter the array size-");
    scanf("%d",&n);
    printf("Enter the elements in array:");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\nMenu-\n1.Bubble sorting\n2.Selection sorting\n3.Insertion sorting\n4.Exit\n");
    do{
        printf("Enter the number from the menu:");
        scanf("%d",&x);
        switch(x){
            case 1: bubblesort(a,n);
                    break;
            case 2: selectionsort(a,n);
                    break;
            case 3: insertionsort(a,n);
                    break;
            case 4: exit(0);
            default: printf("Invalid choice! Enter the number from the menu");
        }
        printf("DO YOU WANT TO CONTINUE?\n Y OR N?\n");
        fflush(stdin);
        scanf("%c",result);
    }
    while(result=='y'||result=='Y');
}

void display(int a[20],int n){
    int i;
    printf("The sorted array is:");
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
}

void bubblesort(int a[20],int x){
    int flag,t;
    for(int i=0;i<x;i++){
        flag=0;
        for(int j=0;j<x-1;j++){
            if(a[j]>a[j+1]){
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
    display(a,x);
}

void selectionsort(int a[20],int x){
    int min,t;
    for(int i=0;i<x-1;i++){
        min=i;
        for(int j=i+1;j<x;j++){
            if(a[min]>a[j])
                min=j;
        }
        if(min!=i){
            t=a[i];
            a[i]=a[min];
            a[min]=t;
        }
    }
    display(a,x);
}

void insertionsort(int a[20],int x){
    int i,j,temp;
    for(i=1;i<x;i++){
        temp=a[i];
        for(j=i-1;j>=0&&a[j]>temp;j--){
            a[j+1]=a[j];
        }
        a[j+1]=temp;
    }
    display(a,x);
}