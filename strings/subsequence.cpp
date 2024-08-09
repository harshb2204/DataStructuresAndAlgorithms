#include<iostream>
using namespace std;

bool isSubSequence(string s1, string s2){
    int j = 0;
    for(int i=0 ;i<s1.length()&&j<s2.length();i++){
        if(s1[i]==s2[j]){
            j++;
        }

        
    }
    return(j==s2.length());
}

int main()
{
   bool a = isSubSequence("ABCDE", "ADE");
   cout<<a<<endl;
   return 0;
}