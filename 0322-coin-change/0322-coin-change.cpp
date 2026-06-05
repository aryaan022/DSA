class Solution {
public:
    const int INF=INT_MAX-1;
    int recur(int n ,vector<int>&coins,int amount,vector<vector<int>>&dp){
        if(amount==0){
            return 0;
        }
        if(n == 0){
            return INF;
        }
        if(dp[n][amount]!=-1){
            return dp[n][amount];
        }

        if(coins[n-1]<=amount){
            return dp[n][amount] =min(1+recur(n,coins,amount-coins[n-1],dp),recur(n-1,coins,amount,dp));
        }
        return dp[n][amount]=recur(n-1,coins,amount,dp);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans =recur(coins.size(),coins,amount,dp);
        if(ans==INF){
            return -1;
        }
        return ans;
    }

};