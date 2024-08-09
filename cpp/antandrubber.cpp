#include <iostream>
using namespace std;


bool antrubber(double l, double v, double r){
     double dist = 0.0;
     double ropel = l;
     double time = 0.0;
     while(dist< ropel){
        dist +=v;
        time +=1;
        ropel +=r;
        if(time>100000){
            return false;
        }
     }
     return true;


}

int main(){
    

    double l, v, r;
    cout<<"Enter length of rope"<<endl;
    cin>>l;

    cout<<"Enter rate of ant"<<endl;
    cin>>v;

    cout<<"Enter rate of extending rubber"<<endl;
    cin>>r;

    bool ans = antrubber(l, v, r);

    cout<<ans<<endl;

}