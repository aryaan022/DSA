class Solution {
public:
    const int inf=1e9;
    int rec(int n ,vector<int>&coins,int amount,vector<vector<int>>&dp){
        if(amount ==0){
            return 0;
        }
        if(n==0){
            return inf;
        }
        if(dp[n][amount]!=-1){
            return dp[n][amount];
        }
        if(coins[n-1]<=amount){
            int take = rec(n, coins, amount - coins[n-1], dp);
            int skip = rec(n-1, coins, amount, dp);

            if(take != inf)
            take++;
            return dp[n][amount] = min(take, skip);
        }
        else{
            return dp[n][amount]=rec(n-1,coins,amount,dp);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans = rec(coins.size(),coins,amount,dp);
        if(ans==inf){
            return -1;
        }
        return ans;
    }
};