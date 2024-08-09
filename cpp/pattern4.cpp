#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i =1;

    int count = 1;
    while(i<=n){
        int j =i;
        while(j<=i*2){
            cout<<count;
            count++;
            j++;
        }
        i++;
        cout<<endl;
    }
   return 0;
}