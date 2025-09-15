#include<iostream>
using namespace std;

void changeA(int *ptr){
    *ptr = 20;
    cout<<*ptr<<endl;

}

int main(){
    int a =10;
    cout<<a<<endl;  
    changeA(&a);
    cout<<a<<endl;  
    return 0;
}