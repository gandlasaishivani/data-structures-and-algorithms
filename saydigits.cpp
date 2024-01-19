#include<iostream>
using namespace std;
void saydigits(int n) {
    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    if(n == 0) {
        return;
    }
    int digit = n%10;
    n = n/10;
    saydigits(n);
    cout<<arr[digit]<<" ";
    
}
int main() {
    saydigits(792);
    cout<<endl;
    saydigits(88);
    return 0;
}
