#include<iostream>
#include<string>
using namespace std;

class Animal{
public:
    string color;
    
    void eat(){
        cout<<"Eats \n";
    }
    void breathe(){
        cout<<"breathes \n";
    }
};

class Fish : public Animal{ //inheritance
public:
    string fins;
    
    void Swim(){
        cout<<"Swims \n";
    }
};

class Dog: public Fish{
    public:
    void tailWag(){
        cout<<"a dog wags its tail \n";
    }
};


int main(){
    return 0;
}