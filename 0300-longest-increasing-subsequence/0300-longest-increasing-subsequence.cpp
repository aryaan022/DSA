class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        unordered_set<int>s(arr.begin(),arr.end()); // storing unique elemts
        vector<int>arr2(s.begin(),s.end()); // copying unique elemtns in array 2

        sort(arr2.begin(),arr2.end()); //soritng in ascending order or increasing order 

        int n=arr.size();
        int m=arr2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        //now finding LCS (longest common subsequence) between arr and arr2 

        for(int i=1;i<=n;i++){
            for(int j =1; j<=m;j++){
                if(arr[i-1]==arr2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};