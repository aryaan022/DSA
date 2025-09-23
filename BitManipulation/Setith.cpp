#include<iostream>
using namespace std;

int SetIthBit(int n , int i){
    int bitMask = 1<<i;
    return (n |bitMask);
}
int main(){
    cout<<SetIthBit(6,3);
    return 0;
}