#include<stdio.h>

int main(){

    int count = 0 ;
    int n;
    printf("enter the number : ");
    scanf("%d",&n);

    for(int i = 2; i<n ;i++ ){
        if(n%i==0 && n!=2){
            count++;
            break;
        }

    }

    if (count==1){
        printf("the number is composite");
    }
    else if(n==2){
        printf("the number is prime");
    }
    else{
        printf("the number is prime");
    }
    
    return 0;
}