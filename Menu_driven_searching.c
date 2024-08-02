#include<stdio.h>
#include<stdlib.h>

int ls(int [],int ,int );
int bs(int[],int,int);
int issorted(int[],int);

int main(){
    int a[20],n,x,y,z;
    char result;
    printf("\nMenu-\n1.Linear serching\n2.Binary searching\n3.Exit\n");
    printf("Enter the size of the array:");
    scanf("%d",&n);
    do{
        printf("Enter the elements of the array:");
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        printf("Enter the number you want to search:");
        scanf("%d",&y);
        printf("Enter the number from the menu:");
        scanf("%d",&x);
        switch(x){
            case 1: z=ls(a,n,y);
                    if(z>=0)
                        printf("The element is found at the position:%d\n",z);
                    else
                        printf("The element not found\n");
                    break;
            case 2: if(issorted(a,n)){
                        z=bs(a,n,y);
                        if(z>0)
                            printf("The element is found at the position:%d\n",z);
                        else
                            printf("The element not found\n");
                        }
                        else
                            printf("The array not sorted\n");
                        break;
            case 3: exit(0);
            default: printf("Invalid choice! Enter the number from the menu\n");
            }
            printf("DO YOU TO CONTINUE?\n Y OR N?\n");
            fflush(stdin);
            scanf("%c",&result);
        }
        while(result=='Y'||result=='y');
}


int ls(int a[20],int n,int y){
    int i;
    for(i=0;i<n;i++){
        if(a[i]==y)
            return(i+1);
    }
    return -1;
}

int issorted(int a[20],int n){
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1])
            return 0;
    }
    return 1;
}

int bs(int a[20],int n,int y){
    int mid,lb=0,ub=n-1;
    while(lb<=ub){
        mid=(lb+ub)/2;
        if(a[mid]<y)
            lb=mid+1;
        else if(a[mid]>y)
            ub=mid-1;
        else if(a[mid]==y)
            return(mid+1);
    }
    return -1;
}