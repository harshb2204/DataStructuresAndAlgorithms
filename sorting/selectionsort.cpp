#include<iostream>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int min_ind = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_ind]){
                min_ind = j;
            }
        }
        int temp;
        temp = arr[min_ind];
        arr[min_ind] = arr[i];
        arr[i] = temp;
    }
}
int main()
{
    int n=5;
    int arr[n] = {8,4,9,10,5};
    selectionSort(arr, n);
    for(int i=0;i<n-1;i++){
        cout<<arr[i]<<endl;
    }
   return 0;
}