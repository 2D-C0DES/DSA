#include<stdio.h>
#include<math.h>

int fact(int a){
    if(a==0 || a==1){
        return 1;
    }
    else{
        return a*fact(a-1) ;
    }

}
int main(){
    int n ,remainder ,original_num ,result =0;
    scanf("%d",&n);

    original_num = n;
    while(original_num != 0){
       remainder = original_num%10;
       result+=fact(remainder);
       original_num /=10 ;

    }

    if(result==n){
        printf("it's an krishnamurthi number");
    }
    else{
        printf("it's not an krishnamurthi number");
    }
    return 0 ;
}