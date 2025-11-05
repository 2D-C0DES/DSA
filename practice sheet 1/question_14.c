#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

bool prime(int n ){
int count = 0 ;
    for(int i =2 ; i<n/2 ; i++){
        if(n%i == 0 ){
            count++;
            break;
        }
    }
    if(count==1 || n==2){
        return false;
    }
    else{
        return true;
    }


}


int main(){
    int a ;
    int n;
    printf("Enter the length of the number : ");
    scanf("%d",&n);
    printf("Enter the number : ");
    scanf("%d",&a);

    char str[n +1];
    sprintf(str , "%d" , a);

    for(int i =0 ;i<n/2 ; i++){
    char temp = str[i] ;
    str[i]  = str[n-i-1];
    str[n-i-1] = temp;

    }
    
    int b = atoi(str);

    if(prime(a) && prime(b)){
        printf("The number %d is Eprime.",a);
    }
    else{
        printf("The number %d is not Eprime.",a);
    }
    
    return 0;
}