#include<iostream>
using namespace std;

int Fib(int n){
    if(n==0 || n==1){
        return n;//0,1
    };

    
    return Fib(n-1) + Fib(n-2);
}

int main (){
    int n; 
    cin>>n;
    Fib(n);
    return 0;
}