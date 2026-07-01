class Solution {
public:
    int rec(int r,int c,int m ,int n,vector<vector<int>>&dp){
        if(r==m-1 && c==n-1){
            return 1;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int bottom =0;
        int right =0;
        if(r+1<m){
            bottom =rec(r+1,c,m,n,dp);
        }
        if(c+1<n){
            right = rec(r,c+1,m,n,dp);
        }
        return dp[r][c] = bottom+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return rec(0,0,m,n,dp);
    }

};