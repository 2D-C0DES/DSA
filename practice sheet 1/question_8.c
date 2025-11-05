#include<stdio.h>

int main(){
    int n;
    printf("enter a number : ");
    scanf("%d",&n);

    if(n%7==0 || n%10==7){
        printf("it's a buzz number.");
    }
    else{
        printf("it's not a buzz number");
    }

    return 0;
}