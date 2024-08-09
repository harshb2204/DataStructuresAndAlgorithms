#include<iostream>
using namespace std;
int main()
{
    int A,B,C;
    cin>>A>>B>>C;
    if((B-A)<=C*2 ){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
   return 0;
}