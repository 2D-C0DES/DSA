#include<stdio.h>

int max,min;

void max_min(int a[],int l,int u){
    int mid;
    if(u==l)
    max = min = a[u];
    else if(u==(l+1)){
        if(a[u]>a[l]){
            max = a[u];
            min = a[l];
        }
        else{
            max = a[l];
            min = a[u];
        }
    }
    else{
        mid = (l+u)/2;
        max_min(a,l,mid);
        int mx = max;
        int mn = min;
        max_min(a,mid+1,u);
        if(mx>max){
            max = mx;
        }
        if(mn<min){
            min = mn;
        }

    }
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

    max_min(a,0,n-1);

    printf("The max element is %d and the min element is %d",max,min);
    return 0;
}