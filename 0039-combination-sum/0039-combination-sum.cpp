class Solution {
public:
    void bt(int n ,vector<int>& candidates, int target,vector<int>&curr,vector<vector<int>>&ans){

        if(n==candidates.size()){
            if(target ==0){
                ans.push_back(curr);
            }
            return;
        }


        if(candidates[n]<=target){
            curr.push_back(candidates[n]);
            bt(n,candidates,target-candidates[n],curr,ans);
            curr.pop_back();
        }

        bt(n+1,candidates,target,curr,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        vector<vector<int>>ans;
        bt(0,candidates,target,curr,ans);
        return ans;
    }
};