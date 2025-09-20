#include <iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v ={1,2,3,4,5};
    vector<int>v1(10,-1);
    cout<<v1.capacity()<<endl; 
    for(int i=0;i<v.size();i++) {
        cout<<v[i]<<" ";
    }
    return 0;
}