#include<iostream>
#include<string>
using namespace std;
string reverse(string s,int st,int e) {
       if(st > e) {
        return s;
       }
       swap(s[st],s[e]);
       st++;e--;
       return reverse(s,st,e);
}
bool checkpalidrome(string s) {
     if(s == reverse(s,0,s.length()-1)) {
        return true;
     }
     return false;
}
int main() {
    string s;
    cout<<"Enter the string : ";
    cin>>s;
    if(checkpalidrome(s))
    cout<<"Palidrome!";
    else
    cout<<"Not a palidrome";
    return 0;
}
