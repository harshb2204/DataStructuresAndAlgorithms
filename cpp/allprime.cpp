#include<iostream>

using namespace std;

int isprime(int n){



if(n==1){

    
    return 0;
}
else if(n==2){
    
    return 1;
}



int flag = 0;

for(int i = 2;i<=n/2;i++){
    if(n%i==0){

        flag = 1;
    }

}
if(flag ==1){
    return 0;
}
else{
    return 1;
}

}

int main(){


    int n;
    cin>>n;


    

    for(int i = 1; i<n; i++){

        if(isprime(i)){
            cout<<i<<endl;
        }
        

    }

}