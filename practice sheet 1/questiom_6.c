#include<stdio.h>
#include<math.h>



int main(){
    int n ,num_digits=0,original_num ;
    scanf("%d",&n);

    original_num = n;
    while(original_num != 0){
       ++num_digits;
       original_num /=10 ;

    }
    int a = n*n;
    int c= pow(10,num_digits);
    int b= a % c;

    if(b==n){
        printf("it's an automorphic number");
    }
    else{
        printf("it's not an automorphic number");
    }
    return 0 ;
}