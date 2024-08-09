#include<iostream>
using namespace std;

/*
NAIVE METHOD
bool sortedornot(int arr[], int n){
    for(int i=0;i<n;i++){
        for(int j =i+1;j<n;j++){
            if(arr[j]<arr[i]){
                return false;
                

            }
            
        }
        
        
        
    }
    return true;
    */

   //Efficient method
   bool isSorted(int arr[], int n){
    for(int i =1; i<n;i++){
        if(arr[i]<arr[i-1]){
            return false;
        }

    }
    return true;
   }




int main()
{
    int arr[] = {1,2,3,6,5,6};
    int n = 6;
    bool result = isSorted(arr, n);
    cout<<result<<endl;

   return 0;
}