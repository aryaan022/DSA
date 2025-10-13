#include<iostream>
#include<string>
#include<vector>

using namespace std;

void subsets(string str,string subset){

    if(str.size()==0){
        cout<<subset<<"\n";
        return;
    }
    char ch =str[0];

    //yes
    subsets(str.substr(1,str.size()-1),subset+ch);
    //no
    subsets(str.substr(1,str.size()-1),subset);
}



int main(){
    string str ="abc";
    string subest ="";
    subsets(str,subest);
    return 0;
}