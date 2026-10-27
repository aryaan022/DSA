class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<char>>grid(m,vector<char>(n,'#'));
        for(int i =0;i<n;i++){
            grid[0][i]='.';
        }
        for(int i=0;i<m;i++){
            grid[i][n-1]='.';
        }
        vector<string>ans;
        for(int i=0;i<m;i++){
            string s="";
            for(int j=0;j<n;j++){
                s=s+grid[i][j];
            }
            ans.push_back(s);
        }
        return ans;
    }
};