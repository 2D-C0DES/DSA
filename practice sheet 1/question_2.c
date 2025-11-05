#include<stdio.h>
#include<math.h>
int main(){
    int n , power = 0 ,remainder ,original_num ,result =0;
    scanf("%d",&n);
    original_num = n ;
    while( original_num != 0){
        original_num /=10;
            ++power ;
    }

    original_num = n ;

    while(original_num != 0){
       remainder = original_num%10;
       result+=pow(remainder,power);
       original_num /=10 ;

    }

    if(result==n){
        printf("it's an armstrong number");
    }
    else{
        printf("it's not an armstrong number");
    }
    return 0 ;
}