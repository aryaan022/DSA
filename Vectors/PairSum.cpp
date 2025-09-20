#include<iostream>
#include<vector>
using namespace std;
//167 problem on leetcode alsso there qill exist a possible pair given already!
vector<int> PairSum(vector<int> arr, int target){
    int start=0;
    int end=arr.size()-1;
    int currSumm=0;
    vector<int> ans;
    while(start<end){
        currSumm =arr[start]+arr[end];
        if(currSumm ==target){
            ans.push_back(start);
            ans.push_back(end);
            return ans;
        }else if(currSumm>target){
            end --;
        }
        else{
            start++;
        }
    }

}

int main(){
    int n;
    cout<<"Size of an vector :"<<endl;
    cin>>n;
    vector<int> vec;
    for(int i=0;i<n;i++){
        int x;
        cout<<"Enter element number vec["<<i<<"]"<<endl;
        cin>>x;
        vec.push_back(x);
    }
    int target;
    cout<<"Enter Targer"<<endl;
    cin>>target;
    vector<int> ans = PairSum(vec,target);
    cout<<"("<<ans[0]<<","<<ans[1]<<")";

    return 0;
}