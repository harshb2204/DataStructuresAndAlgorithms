#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    int n = 5;

    int v1[n];

    

    cout<<"Enter elements of vector"<<endl;

    for(int i = 0; i<n;i++){
        cin>>v1[i];

    }
    int ans = INT32_MIN;

    for(int i = 0; i<n;i++){
        int count = 0;
        int j = i;
        int k = i;
        while(j<n && k<n){
            k++;
            if(v1[k]>v1[j]){
                count ++;
                j = k;
            }
            

        }
        ans = max(ans, count);
    }


    cout<<ans<<endl;
}