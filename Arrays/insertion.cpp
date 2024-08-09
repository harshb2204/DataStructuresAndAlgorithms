#include<iostream>
using namespace std;

void insert(int arr[], int n, int x, int pos,int cap){
    if(n==cap){
        cout<<"No space for insertion"<<endl;
    }

    int ind = pos-1;
    for(int i=n-1;i>=ind;i--){
        arr[i+1] = arr[i];
    }
    arr[ind] = x;
    

}
int main()
{
    int n = 6;
    int arr[n] = {1,2,3,4};
    insert(arr, 6 , 4 , 2, 2);
    for(int i=0; i<n;i++){
        cout<<arr[i]<<endl;
    }
   return 0;
}