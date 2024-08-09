#include<iostream>
using namespace std;
int main()
{
    int x;
    cout<<"Enter the number you want to check : "<<endl;
    cin>>x;
    int rev = 0;
    int last = 0;
    int temp = x;
    while(temp>0){
        last = temp%10;
        temp = temp/10;
        rev = rev * 10 + last;

    }
    if(x==rev){
        cout<<"yes it is a palindrome";

    }
    else{
        cout<<"Its not a palindrome";
    }

   return 0;
}