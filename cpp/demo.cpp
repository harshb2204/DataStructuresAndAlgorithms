#include<iostream>
using namespace std;
int main(){
    char ch;
    cout<<"enter your character";
    cin>>ch;
    if(ch>=48&&ch<=57){
        cout<<"Its a digit";

    }
    else if(ch>=65&&ch<=90){
    cout<<"its uppercase";
            }


           else if(ch>=97&&ch<=122){
    cout<<"It is lowercase";
    }

    return 0;

}
