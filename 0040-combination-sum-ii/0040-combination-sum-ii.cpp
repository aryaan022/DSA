class Solution {
public:
    void cal(int n , int t,vector<int>&arr, vector<int>&curr,vector<vector<int>>&ans){
        if(n==arr.size()){
            if(t==0){
                ans.push_back(curr);
            }
            return;
        }

        int next= n+1;
        if(arr[n]<=t){
            curr.push_back(arr[n]);
            cal(n+1,t-arr[n],arr,curr,ans);
            curr.pop_back();
            while(next<arr.size() && arr[next]==arr[n]){
                next++;
            }
        }
        cal(next,t,arr,curr,ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int t) {
        vector<int>curr;
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        cal(0,t,arr,curr,ans);
        return ans;
    }
};