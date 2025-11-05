#include<stdio.h>



void merge(int a[],int low,int mid,int high){
    int i,j,k;
    i=low;
    k=0;
    j = mid +1;
    int b[high -low +1];

    while((i<=mid) && (j<=high)){
        if(a[i]<a[j]){
            b[k] = a[i];
            i++;
            k++;
        }

        else{
            b[k] = a[j];
            j++;
            k++;
        }
    }

    while(i<=mid){
        b[k] = a[i];
        i++;
        k++;

    }
    while(j<=high){
        b[k] = a[j];
        j++;
        k++;
    }


    for(int p=0;p<k;p++){
        a[low + p] = b[p];
    }
}

void merge_sort(int a[],int low,int high){
      if(low<high){
        int mid = (low + high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
      }
}



int main(){
    int n;
    
    printf("Enter the number of element of array: ");
    scanf("%d",&n);
    int a[n];
    
    //for taking input
    for(int i = 0;i<n;i++){
        printf("Enter the %dth elemnt:",i);
        scanf("%d",&a[i]);
    }

    merge_sort(a,0,n-1);
    //for printing the sorted array
    for(int i = 0;i<n;i++){
        printf("%d ",a[i]);
        
    }

    return 0;
}