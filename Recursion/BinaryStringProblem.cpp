#include<iostream>
using namespace std;


void binary(int n,int lastplace,string ans){
    if(n==0){
        cout<<ans<<endl;
        return;
    }


    if(lastplace!=1){
        binary(n-1,0,ans+'0');
        binary(n-1,1,ans+'1');
    }
    else{
        binary(n-1,0,ans+'0');
    }

}

int main(){
    string ans ="";
    binary(3,0,ans);
    return 0;
}