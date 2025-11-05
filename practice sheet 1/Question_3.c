#include<stdio.h>
#include<string.h>
int main(){
    char str [50];
    gets(str);
    int l = strlen(str);
    char  str_2[50];
    for(int i=0;i< l ; i++){
        str_2[l-i-1] = str[i];
    }

    int count = 0;
    for(int i=0 ; i< l ;i++ ){
       if( str[i] == str_2[i] )
        count++;
    }
        

        if(count == l){
            printf("the number is palindrome");
        }
        else{
            printf("the number is not a palindrome");        
            }
            
            return 0;
    
}