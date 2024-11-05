#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void strev(char[],int);

int main(){
    int i=0;
    char x[15];
    printf("Enter the string you want to reverse:\n");
    scanf("%s",x);
    printf("The reversed string is:\n");
    strev(x,i);
}

void strev(char a[15],int i){
    if(a[i]=='\0')
        return;
    strev(a,i+1);
    printf("%c",a[i]);
}