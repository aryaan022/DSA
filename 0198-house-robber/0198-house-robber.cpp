class Solution {
public:
    int rec(int i,vector<int>& nums,vector<int>&dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take =nums[i]+rec(i+2,nums,dp);
        int skip = rec(i+1,nums,dp);
        return dp[i]=max(take,skip);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return rec(0,nums,dp);
    }
};