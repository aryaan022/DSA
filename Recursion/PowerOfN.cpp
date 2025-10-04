#include<iostream>
#include<vector>
using namespace std;


int pow(int x ,int n){
    if(n==0){
        return 1;
    }
    x^n/2;
    int halfpow=pow(x,n/2);
    int halfpowsquare = halfpow*halfpow;

    if(n%2 !=0){
        //odd
        return x*halfpowsquare;
    }
    return halfpowsquare;
}



int main(){
    cout<<pow(2,10)<<endl;
    return 0;

}