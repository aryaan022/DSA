#include<iostream>
using namespace std;

int ClearIthBit(int n , int i){
    int bitMask = ~(1<<i);
    return (n & bitMask);
}
int main(){
    cout<<ClearIthBit(6,1);
    return 0;
}