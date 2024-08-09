#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter any number"<<endl;
    int x;
    cin>>x;
    int res = 1;
    int count = 0;
    for(int i =2;i<=x;i++){
        res = res*i;
    }
    while(res%10==0){
        count++;
        res = res/10;
    }
    cout<<count;


   return 0;
}