#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter any number"<<endl;
    int x;
    cin>>x;
    int res = 1;
    for(int i =2;i<=x;i++){
        res = res*i;
    }
    cout<<"Factorial is "<<res;

    
   return 0;
}