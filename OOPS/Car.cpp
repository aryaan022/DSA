#include<iostream>
#include<string>
using namespace std;

class Car{
    string name;
    string color;
public:
    Car(string nameVal,string colorVal){
        name=nameVal;
        color=colorVal;
        cout<<"constructor is called object being created \n";
    }
    void start(){
        cout<<"car has started...\n";
    }
    void stop(){
        cout<<"car has stopped...\n";
    }

    //getter
    string getName(){
        return name;
    }
    string getColor(){
        return color;
    }
};

int main(){
    Car c1("maruti800","white");
    cout<<c1.getName()<<endl<<c1.getColor();
    return 0;
}