class Solution {
public:
    bool solve(int n, int W , vector<int>&nums,vector<vector<int>>&dp){
        if(W==0){
            return true;
        }
        if(n==0){
            return false;
        }
        if(dp[n][W]!=-1){
            return dp[n][W];
        }
        if(nums[n-1]<=W)//valid
        {
            return dp[n][W]=solve(n-1,W-nums[n-1],nums,dp) || solve(n-1,W,nums,dp);
        }
        return dp[n][W]=solve(n-1,W,nums,dp);
    }
    bool canPartition(vector<int>& nums) {
        int ts=0;
        for(int i =0;i<nums.size();i++){
            ts=ts+nums[i];
        }
        if(ts%2!=0){
            return false;
        }
        int W=ts/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(W+1,-1));
        return solve(nums.size(),W,nums,dp);
    }
};