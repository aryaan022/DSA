#include<iostream>
#include<string>
using namespace std;
//example of runtime polymorphism!
class Parent{
public:
    void  show(){
        cout<<"parent class show";
    }
};
class Child :public Parent{
public:
    void  show(){
        cout<<"Child class show";
    }
};


int main(){
    Child c1;
    c1.show();
    return 0;
}