#include<stdio.h>
#include<stdbool.h>

bool magic( int n){
    int sum = 0 , remainder;

    while(n!=0){
        remainder = n%10;
        sum += remainder;
        n /=  10;
    }
    if (sum >=10 ){
        magic(sum);
    }
    else if(sum ==  1){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n ;
    printf("enter a number: ");
    scanf("%d",&n);
    if( magic(n)){
        printf("it's a magic number .");
    }
    else{
        printf("it's not a magic number .");
    }
    return 0 ;
}