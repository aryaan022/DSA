class Solution {
public:
    bool recur(int n,vector<int>&nums,int t,vector<vector<int>>&dp){
        if(t==0){
            return true;
        }
        if(n==0){
            return false;
        }
        if(dp[n][t]!=-1){
            return dp[n][t];
        }
        if(nums[n-1]<=t){
            return dp[n][t]= recur(n-1,nums,t-nums[n-1],dp) || recur(n-1,nums,t,dp);
        }
        return dp[n][t]=recur(n-1,nums,t,dp);
    }
    bool canPartition(vector<int>& nums) {
        int ts=0;
        for(int i=0;i<nums.size();i++){
            ts=ts+nums[i];
        }
        if(ts%2!=0){
            return false;
        }
        vector<vector<int>>dp(nums.size()+1,vector<int>((ts/2)+1,-1));
        return recur(nums.size(),nums,ts/2,dp);
    }
};