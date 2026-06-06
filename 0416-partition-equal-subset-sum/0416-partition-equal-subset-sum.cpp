class Solution {
public:
    bool rec(int n ,int t,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(t==0){
            return true;
        }
        if(n==0){
            return false;
        }
        if(dp[n][t] != -1){
            return dp[n][t];
        }
        if(nums[n-1]<=t){
            bool take = rec(n-1,t-nums[n-1],nums,dp);
            bool leave = rec(n-1,t,nums,dp);
            return dp[n][t]= take || leave;
        }
        else{
            return dp[n][t]=rec(n-1,t,nums,dp);
        }
    }
    bool canPartition(vector<int>& nums) {
        int ts=0;
        for(int i=0;i<nums.size();i++){
            ts=ts+nums[i];
        }

        if(ts%2!=0){
            return false;
        }
        int target = ts/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,-1));
        return rec(nums.size(),target,nums,dp);
    }
};