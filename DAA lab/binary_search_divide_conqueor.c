#include<stdio.h>

int binarysearch(int a[],int l, int u, int x){
    int mid;
    if(l<=u){
        mid = (l+u)/2;
        if(a[mid] == x){
            return mid;
        }
        if(a[mid]<x){
            return binarysearch(a,mid+1,u,x);
        }
            return binarysearch(a,l,mid-1,x);

        

    }
    return -1 ;
}

int main(){
    int n;
    printf("enter the number of element of the array:");
    scanf("%d",&n);

    int a[n];

    for(int i=0;i<n;i++){
        printf("Enter the %dth element:",i);
        scanf("%d",&a[i]);
    }

    int value;
    printf("Enter the value to search:");
    scanf("%d",&value);
int k = binarysearch(a,0,n-1,value);
if(k!= -1){
printf("Element found at index %d",k);
}

else{
    printf("Element not found");
}


return 0;
}