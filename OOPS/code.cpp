#include<iostream>
#include<string>
using namespace std;

class Student{
    //properties or attributes;
    string name;
    float cgpa; //it will be private by default

public:
    //methods
    void getPercentage(){
        cout<<(cgpa*10)<<"%";
    }
    //Setters
    void setName(string nameVal){
        name = nameVal;
    }
    void setCgpa(float cgpaVal){
        cgpa = cgpaVal;
    }
    //getters

    string getName(){
        return name;
    }
    float getCgpa(){
        return cgpa;
    }
    
};
int main(){
    Student s1;
    s1.setName("Shradhha");
    s1.setCgpa(9.1);
    cout<<s1.getName()<<endl;
    cout<<s1.getCgpa()<<endl;
    return 0;
}