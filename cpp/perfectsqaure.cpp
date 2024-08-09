#include<iostream>
using namespace std;

int main(){

int n;
cin>>n;

if(n==1){

    cout<<"Perfect square";
}


int flag = 0;

for(int i = 1;i<n/2;i++){
    if(n==i*i){

        flag = 1;
    }

}
if(flag ==1){
    cout<<"Perfect sqaure"<<endl;
}
else{
    cout<<"Not a perfect sqaure"<<endl;
}

}