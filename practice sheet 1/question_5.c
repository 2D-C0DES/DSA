#include<stdio.h>



int main(){
    int n ,remainder ,original_num ,result =0;
    scanf("%d",&n);

    original_num = n;
    while(original_num != 0){
       remainder = original_num%10;
       result+=remainder;
       original_num /=10 ;

    }

    if(result==n){
        printf("it's an neon number");
    }
    else{
        printf("it's not an neon number");
    }
    return 0 ;
}