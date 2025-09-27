#include<iostream>
#include<string>
using namespace std;

class Print{
    public:
    void show(int x){
        cout<<"int : "<<x<<endl;
    }
    void show(string str){
        cout<<"String : "<<str<<endl;
    }
};
int main(){
    Print obj1;
    obj1.show(25);
    obj1.show("Apna");
    return 0;
}