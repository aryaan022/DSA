class Solution {
public:
    void cal(int n,vector<int>&arr,int t,vector<int>&curr,vector<vector<int>>&ans){
        if(n==arr.size()){
            if(t==0){
                ans.push_back(curr);
            }
            return;
        }
        

        if(arr[n]<=t){
            //taaking the number
            curr.push_back(arr[n]);
            cal(n,arr,t-arr[n],curr,ans);
            curr.pop_back();
        }
        cal(n+1,arr,t,curr,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int t) {
        vector<int>curr;
        vector<vector<int>>ans;
        cal(0,arr,t,curr,ans);
        return ans;
    }
};