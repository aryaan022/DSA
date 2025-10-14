#include<iostream>
using namespace std;

bool Ispower(int n){
    if(!(n & (n-1))){
        return true;
    }
    return false;
}     



int main(){
    cout<<Ispower(4);
    return 0;
}