class Solution {
public:
    int unique(int r,int c, int m,int n ,vector<vector<int>>&dp){
        if(r==m-1 && c==n-1){
            return 1;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int d=0,right=0;
        if(r+1<m){
            right = unique(r+1,c,m,n,dp);
        }
        if(c+1<n){
            d=unique(r,c+1,m,n,dp);
        }
        return dp[r][c]=right+d;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return unique(0,0,m,n,dp);
        
    }
};