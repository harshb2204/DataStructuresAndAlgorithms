#include<iostream>
#include <bits/stdc++.h>
using namespace std;


vector<int> reversearray(int arr[], int n){
    vector<int> v;
    for(int i = n-1;i>=0;i--){
        v.push_back(arr[i]);

    }
    return v;

}
int main()
{

int arr[] = {1,2,3,4,5};
vector<int> v = reversearray(arr, 5);
for(auto i :v){
    cout<<i<<endl;
}
   return 0;
}