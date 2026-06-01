class Solution {
public:
    // int Mincost(int n,vector<int>cost,vector<int>&dp){
    //     if(n<=1){
    //         return 0;
    //     }
    //     if(dp[n]!=-1){
    //         return dp[n];
    //     }
    //     int path1 =cost[n-1]+ Mincost(n-1,cost,dp);
    //     int path2 = cost[n-2]+Mincost(n-2,cost,dp);

    //     return dp[n]=min(path1,path2);
    // }

//tabulation form 
    int Mincost(int n,vector<int>cost,vector<int>&dp){
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<=n;i++){
            dp[i]=min(cost[i-1]+dp[i-1],cost[i-2]+dp[i-2]);
        }
        return dp[n];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return Mincost(n,cost,dp);
    }
};