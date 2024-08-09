#include<iostream>
using namespace std;

void deleteEle(int arr[], int n, int x ){
    int i;
    for(i =0; i<n; i++){
        if(arr[i]==x){
            break;
        }
        if(i==n){
        cout<<"No element found"<<endl;
        
    }
        
    }
    
    
    for(int j = i; j<n-1;j++){
        arr[j] = arr[j+1];
    }
}
int main()
{
    int n = 6;
    int arr[n] = {1,2,3,4,5,6};
    
    deleteEle(arr,6,3);
    n--;
    for(int i =0;i<n;i++){
        cout<<arr[i]<<endl;
    }
       return 0;
}