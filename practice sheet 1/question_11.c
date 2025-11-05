#include<stdio.h>

int main(){
    int m,n;
    printf("enter the two numbers : ");
    scanf("%d %d",&m,&n);

    int sum_1=0,sum_2=0;


    for(int i=1 ; i<= m/2 ; i++){
        if(m%i == 0){
            sum_1+= i ;
        }
    }

    for(int i=1 ; i<= n/2 ; i++){
        if(n%i == 0){
            sum_2+= i ;
        }
    }

if (sum_1 == n &&  sum_2== m){
    printf("The pair is amicable pair");
}
else{
        printf("The pair is not amicable pair");

}


return 0;
}