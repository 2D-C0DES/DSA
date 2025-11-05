#include<stdio.h>

int partition(int a[],int low,int high){
    int i = low +1;
    int j = high;
    int pivot = low;
    int temp;

    do{
        while(a[i]<=a[pivot]){
            i++;
        }
        while(a[j]>a[pivot]){
            j--;
        }
        
       if (i<j){
        //swapping element[i] and element[j]
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;

       }


        

    }while(i<j);
    
    //swapping pivot and element[j]
    temp = a[j];
    a[j] = a[pivot];
    a[pivot] = temp;


    return j;


}

void quick_sort(int a[],int low,int high){

    int partition_index;
    if(low<high){   //this condition is to make sure that the process stops when the subarray has only one element
            partition_index = partition(a,low,high);

            quick_sort(a,low,partition_index -1);
            quick_sort(a,partition_index + 1,high);
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

    quick_sort(a,0,n-1);
    //for printing the sorted array
    for(int i = 0;i<n;i++){
        printf("%d ",a[i]);
        
    }

    return 0;
}