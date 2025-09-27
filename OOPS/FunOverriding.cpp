#include<iostream>
#include<string>
using namespace std;
//example of runtime polymorphism!
class Parent{
public:
    void  show(){
        cout<<"parent class show";
    }

    virtual void hello(){
        cout<<"parent hello \n";
    }
};
class Child :public Parent{
public:
    void  show(){
        cout<<"Child class show";
    }

    void hello(){
        cout<<"child hello";
    }
};


int main(){
    Child c1;
    Parent *ptr;
    ptr = &c1;//Run time binding possible due to inheritance;
    ptr->hello(); //virtual function;
    c1.show();
    return 0;
}