#include<iostream>
using namespace std;
int main()
{
    int x;
    cin>>x;
    int count = 0;
    while(x>0){
        x= x/10;
        count++;

    }
    cout<<endl;
    cout<<"Number of digits are : "<<count;
    
   return 0;
}