#include<iostream>
#include<string>
using namespace std;


//abstract class
class Shape{
public:
    virtual void draw() =0; //pure virtual function or abstract function
};

class Circle : public Shape{
    public:
    void draw(){
        cout<<"draw circle \n";
    }
};

class Square : public Shape{
    public:
    void draw(){
        cout<<"draw Square \n";
    }
};
int main(){
    Circle cir1;
    cir1.draw();

    Square sq1;
    sq1.draw();
    return 0;
}