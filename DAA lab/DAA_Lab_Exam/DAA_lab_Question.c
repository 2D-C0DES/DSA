#include<stdio.h>

int maximum , minimum ;  // Globally declared max , min

void Find_max_min(int a[],int l,int u){
    int mid;
    if(u==l)            // Finding max , min for single element array
    maximum = minimum = a[u];
    else if(u==(l+1)){  // Finding max , min for two element array
        if(a[u]>a[l]){
            maximum = a[u];
            minimum = a[l];
        }
        else{
            maximum = a[l];
            minimum = a[u];
        }
    }
    else{                   // array with more than two element
        mid = (l+u)/2;
        Find_max_min(a,l,mid);
        int mx = maximum ;
        int mn = minimum ;
        Find_max_min(a,mid+1,u);
        if(mx>maximum){
            maximum = mx;
        }
        if(mn<minimum){
            minimum = mn;
        }

    }
}

int bin_search(int a[],int l, int u, int x){
    int mid;
    if(l<=u){
        mid = (l+u)/2;
        if(a[mid] == x){
            return mid;
        }
        if(a[mid]<x){
            return bin_search(a,mid+1,u,x);
        }
            return bin_search(a,l,mid-1,x);

        

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

    Find_max_min(a,0,n-1);

    printf("The maximum element is %d and the minimum element is %d \n",maximum,minimum);

    int mean = (maximum + minimum)/2 ;

    printf("The mean of maximum and minimum elemenet is %d \n" , mean);

    int key = bin_search(a,0,n-1,mean);
    if(key != -1){
    printf("Mean found at index %d",key);
    }

    else{
        printf("Mean not found in the array");
    }


    return 0;
}