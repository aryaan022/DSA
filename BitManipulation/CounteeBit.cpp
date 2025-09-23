#include<iostream>
using namespace std;

int CountSetBits(int n){
    int count=0;
    while(n>0){
        int lastdig= n&1;
        count = count + lastdig;
        n=n>>1;
    }
    cout<<"Count of set bits is :"<<count<<endl;
    return count;
}

int main(){
    int n = 10;
    CountSetBits(n);
    return 0;
}