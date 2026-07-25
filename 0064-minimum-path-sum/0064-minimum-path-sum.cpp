class Solution {
public:
    int cal(int row,int col,int m,int n,vector<vector<int>>&g,vector<vector<int>>&dp){
        if(row==m-1 && col==n-1){
            return g[row][col];
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int down =INT_MAX;
        int right=INT_MAX;
        //down
        if(row+1<m){
            down=cal(row+1,col,m,n,g,dp);
        }
        //right
        if(col+1<n){
            right=cal(row,col+1,m,n,g,dp);
        }
        return dp[row][col]=g[row][col]+min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m =grid.size();
        int n =grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return cal(0,0,m,n,grid,dp);
        
    }
};