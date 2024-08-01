#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int primeNumber(int);
int armstrongNumber(int);
int sumDigit(int);

int main(){
    int a,res,z;
    char user;
    printf("\nMenu-\n1.To check if number is prime number\n2.To check if the number is armstrong number\n3.To add the digits of the number\n4.Exit\n");
    do{
        printf("Enter a number:");
        scanf("%d",&a);
        printf("\nEnter the number of your choice:");
        scanf("%d",&res);
        switch(res)
        {
            case 1: if(primeNumber(a))
                        printf("The number is not a prime number");
                    else 
                        printf("The number is a prime number");
                    break;
            case 2: if(armstrongNumber(a))
                        printf("The number is an armstrong number");
                    else
                        printf("The number is not an armstrong number");
                    break;
            case 3: z=sumDigit(a);
                    printf("The sum of the digits is:%d",z);
                    break;
            case 4: exit(0);
            default: printf("Invalid choice! Enter from the given numebrs");
        }
        printf("\nDO YOU WANT TO CONTINUE?\n Y OR N?\n");
        fflush(stdin);
        scanf("%c",&user);
    }
    while(user=='y'||user=='Y');
}

int primeNumber(int x){
    int i;
    for( i=2;i<=x/2;i++){
        if(x%i==0)
            return 1;        
    }
    return 0;
}

int armstrongNumber(int x){
    int n,rem,result=0,dig=0;
    n=x;
    while(n>0){
        n=n/10;
        dig++;
    }
    n=x;
    while(n>0){
        rem=n%10;
        result=result+pow(rem,dig);
        n=n/10;
    }
    if(result==x)
        return 1;
    else
        return 0;
}


int sumDigit(int x){
    int r,sum=0;
    while(x>0){
        r=x%10;
        sum=sum+r;
        x=x/10;
    }
    return(sum);
}