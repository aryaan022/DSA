class Solution {
public: 

    void dfs(int r, int c,vector<vector<char>>&graph,int n,int m){
        graph[r][c]='0';
        //up
        if(r-1>=0 && graph[r-1][c]=='1'){
            dfs(r-1,c,graph,n,m);
        }
        //down
        if(r+1<n && graph[r+1][c]=='1'){
            dfs(r+1,c,graph,n,m);
        }
        //left
        if(c-1>=0 && graph[r][c-1]=='1'){
            dfs(r,c-1,graph,n,m);
        }
        //right
        if(c+1<m && graph[r][c+1]=='1'){
            dfs(r,c+1,graph,n,m);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
      int n= grid.size();
      int m = grid[0].size();
      int count =0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1'){
                dfs(i,j,grid,n,m);
                count = count+1;
            }
        }
      }
      return count;  
    }
};