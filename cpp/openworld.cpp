#include<iostream>
using namespace std;
void targetsum(int arr[], int n, int x){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==x){
                cout<<"Indices are: "<<i<<j;

            }
            
        }
    }
}
int main(){
    int n = 5;
    int arr[] = {1,2,3,4,5};
    int x = 4;
    targetsum(arr,n,4);
    return 0;
    
}
