#include<iostream>
using namespace std;

void swap(int *x, int *y){
    int temp;
     temp = *y;
    *y = *x;
    *x = temp;

}

void bubbleSort(int arr[], int n){
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);

                

            }
        }
    }
}
int main()
{
    int n=5;
    int arr[n] = {8,4,9,10,5};
    bubbleSort(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
   return 0;
}