#include<iostream>
#include<string>
//example of copy constructore
using namespace std;

class Car{
public:
    string name;
    string color;
    int *mil;

    Car(string name, string color){
        this->name = name;
        this->color=color;
        mil = new int;
        *mil=12;
    }
    Car(Car &original){//custom  copy constructor
        cout<<"Copying original to new";
        name =original.name;
        color=original.color;
        mil =new int;
        *mil = *original.mil;
    }
    //destructor to de allocate dynmicall allocated memory
    ~Car(){
        cout<<"deleting object";
        if(mil != NULL){
            delete mil; //deleting where it poiniting thqat memory!
            mil = NULL; 

        }
    }
};

int main(){
    Car c1("maruti800", "White");
    Car c2(c1);
    cout<<c2.name<<endl; //maruti800
    cout<<c2.color<<endl;// whhite
    return 0;
}