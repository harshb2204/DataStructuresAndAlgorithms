#include<iostream>
using namespace std;
void insertatbeg(int arr[], int n, int x, int pos){
    

    int ind = pos-1;
    for(int i=n-1;i>=ind;i--){
        arr[i+1] = arr[i];
    }
    arr[ind] = x;
    

}
int main()
{
    int n =6;
    int arr[n] = {1,2,3,4,5};
    insertatbeg(arr, 6, 98, 1);
    for(int i=0; i<n;i++){
        cout<<arr[i]<<endl;
    }



   return 0;
}