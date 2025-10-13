#include<iostream>
#include<string>
#include<vector>

using namespace std;
void per(string str,string ans){
    if(str.size()==0){
        cout<<ans<<"\n";
        return; 
    }

    for(int i =0;i<str.size();i++){
        char ch=str[i];
        string nextstr= str.substr(0,i)+str.substr(i+1);
        per(nextstr,ans+ch);
    }
}


int main(){
    string str = "abc";
    string ans ="";
    per(str,ans);
    return 0;
}