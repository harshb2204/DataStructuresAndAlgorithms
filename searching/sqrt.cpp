#include<iostream>
using namespace std;

/*Naive approach using linear search
int sqrt(int x){
    int ans = 0;
    for(int i = 1;i<=x;i++){
        if(i*i<=x){
            ans = i;
        }
        else{
            break;
        }
    }
    return ans;

}
*/

int sqrt(int x){
    int low = 1;
    int high = x;
    int ans = 1;
    while(low<=high){
    int mid = (low+high)/2;
    if(mid*mid<=x){
        ans = mid;
        low = mid +1;

    }
    else{
        high = mid-1;
    } 

    
    
    
    } 
    return ans;
    
}

int main()
{
    
    int b = sqrt(54);
    cout<<b<<endl;

   return 0;
}