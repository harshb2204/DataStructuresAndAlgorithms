#include<iostream>
using namespace std;

int SeconDlargest(int arr[], int n){
    int res= -1;
    int largest = 0;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[largest]){
            res = largest;
            largest = i;
        }
        else if (arr[i]!=arr[largest])
        {
            if(res==-1||arr[i]>arr[res])
            res = i;
        }
        
    }
    return res;
}

int main()
{
    int arr[] = {1,2,3,4,5,6};
    int secondlargestele = SeconDlargest(arr,6);
    cout<<secondlargestele<<endl;


   return 0;
}