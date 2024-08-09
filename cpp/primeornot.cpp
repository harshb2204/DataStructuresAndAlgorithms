#include<iostream>
using namespace std;

int main(){

int n;
cin>>n;

if(n==1){

    cout<<"not a prime";
    
}
else if(n==2){
    cout<<"Prime"<<endl;
    
}



int flag = 0;

for(int i = 2;i<n/2;i++){
    if(n%i==0){

        flag = 1;
    }

}
if(flag ==1){
    cout<<"not Prime"<<endl;
}
else{
    cout<<"prime"<<endl;
}

}