class Solution {
public:

    int rec(int r,int c,int m ,int n,vector<vector<int>>&dp,vector<vector<int>>&g){
        if(g[r][c]==1){
            return 0;
        }
        if(r==m-1 && c==n-1){
            return 1;
        }
        
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int bottom =0;
        int right =0;
        if(r+1<m){
            bottom =rec(r+1,c,m,n,dp,g);
        }
        if(c+1<n){
            right = rec(r,c+1,m,n,dp,g);
        }
        return dp[r][c] = bottom+right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return rec(0,0,m,n,dp,obstacleGrid);
    }
};