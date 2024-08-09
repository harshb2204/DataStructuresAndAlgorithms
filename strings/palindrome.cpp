#include<iostream>
using namespace std;
bool palindrome(string str){

    int begin = 0;
    int end = str.length() -1;
    while(begin<end){
        if(str[begin]!=str[end]){
            return false;
            begin++;
            end--;
        }
        return true;
    }

    
   
    
    
   

}
int main()
{
   string str;
   cout<<"Enter a string: "<<endl;
   cin>>str;
   bool a = palindrome(str);
   if(a==0){
    cout<<"It is not a palindrome"<<endl;

   }
   else{
    cout<<"It is a palindrome"<<endl;
   }
   
 
   return 0;
}