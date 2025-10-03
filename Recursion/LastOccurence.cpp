#include<iostream>
#include<vector>
using namespace std;

int LastOccur(vector<int> arr,int i,int target){
    if(i==arr.size()){
        return -1;
    }
    int idcfound = LastOccur(arr,i+1,target);
    if(idcfound ==-1 && arr[i]==target){
        return i;
    }
    return idcfound;
}

int main(){
    vector<int> arr= {1,2,3,3,3,4};
    cout<<LastOccur(arr,0,3)<<endl;
    return 0;
}