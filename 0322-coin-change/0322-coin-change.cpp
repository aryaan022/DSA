class Solution {
public: 
    const int INF=INT_MAX-1;

    int rec(int n,vector<int>&coins , vector<vector<int>>&dp,int amount){
        if(amount==0){
            return 0;
        }
        if(n==0){
            return INF;
        }
        if(dp[n][amount]!=-1){
            return dp[n][amount];
        }
        if(coins[n-1]<=amount){
            return dp[n][amount]=min(1+rec(n,coins,dp,amount-coins[n-1]),rec(n-1,coins,dp,amount));
        }
        else{
            return dp[n][amount]=rec(n-1,coins,dp,amount);
        }

        return dp[n][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans = rec(coins.size(),coins,dp,amount);
        if(ans==INF){
            return -1;
        }
        return ans;
    }
};