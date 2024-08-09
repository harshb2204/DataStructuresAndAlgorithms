#include<iostream>
using namespace std;

void reversal(int arr[], int n){
   int high = n-1;
   int low = 0;
   while(low<high){
    int temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;
    low++;
    high--;
   }
    
}



int main()
{
    int arr[] = {1,2,3,4,5,6};
    int n=6;
    reversal(arr, 6);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }

   return 0;
}