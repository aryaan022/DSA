#include<iostream>
#include<string>
using namespace std;



void removeDuplictes(string str, string ans,int i,int map[26]){
    if(i==str.size()){
        cout<<"ans is :"<<ans<<endl;
    }
    char ch =str[i];
    int mapidx =(int)(ch-'a'); //a -->0
    if(map[mapidx]==true){
        removeDuplictes(str,ans,i+1,map);
    }else{
        map[mapidx]=true;
        removeDuplictes(str,ans+str[i],i+1,map);
    }
}

int main(){
    string str = "aaabb";
    string ans ="";
    int map[26] ={false};
    removeDuplictes(str,ans,0,map);
    return 0;
}