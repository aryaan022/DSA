#include<iostream>
using namespace std;

int getIthBit(int n , int i){
    int bitMask = 1<<i;
    if(!(n &bitMask)){
        return 0;
    }
    else{
        return 1;
    }
}
int main(){
    cout<<getIthBit(6,2);
    return 0;
}