#include<iostream>
using namespace std;

int largestele(int arr[], int n ){
    int large=0;
    for(int i = 1;i<n;i++){
        if(arr[i]>arr[large]){
            large = i;
        }

    }
    return large;

}
int main()
{
    int n = 6;
    int arr[n] = {1,2,3,4,5,6};
    int largesteleind = largestele(arr, n);
    cout<<largesteleind<<endl;
    
   return 0;
}