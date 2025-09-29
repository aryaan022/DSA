#include<iostream>
using namespace std;
//recursion when function call itself repeatidly

//recusrive function
void func(){
    cout<< "Func call... work \n";
    func();
}
int main(){
    func();
    return 0;
}