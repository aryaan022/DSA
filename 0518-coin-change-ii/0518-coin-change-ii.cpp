class Solution {
public:
    int rec(int n,int amount ,vector<int>&coins,vector<vector<int>>&dp){
        if(amount == 0){
            return 1;
        }
        if(n==0){
            return 0;
        }
        if(dp[n][amount]!=-1){
            return dp[n][amount];
        }
        if(coins[n-1]<=amount){
            return dp[n][amount]= rec(n,amount-coins[n-1],coins,dp)+rec(n-1,amount,coins,dp); 
        }
        return dp[n][amount]= rec(n-1,amount,coins,dp);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return rec(coins.size(),amount,coins,dp);
    }
};