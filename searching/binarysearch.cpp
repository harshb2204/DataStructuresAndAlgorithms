#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int x){
    int low=0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid]>x){
            high = mid-1;
        }
        else if(arr[mid]<x){
            low = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int n =5;
    int arr[n] = {1,2,3,4,5};
    int b1 = binarySearch(arr, n, 3);
    cout <<b1 <<endl;
    
   return 0;
}