class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&grid,int n,int m){
        grid[row][col]=1;
        if(row+1<n &&grid[row+1][col]==0){
            dfs(row+1,col,grid,n,m);
        }
        if(row-1>=0 &&grid[row-1][col]==0){
            dfs(row-1,col,grid,n,m);
        }
        if(col+1<m &&grid[row][col+1]==0){
            dfs(row,col+1,grid,n,m);
        }
        if(col-1>=0 &&grid[row][col-1]==0){
            dfs(row,col-1,grid,n,m);
        }
    }

    

    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m= grid[0].size();
        int count =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && (i==0 || i==n-1 || j==0 || j==m-1)){
                    //0 on the boundary perform  dfs
                    dfs(i,j,grid,n,m);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    count++;
                    dfs(i,j,grid,n,m); 
                }
            }
        }
        return count;
    }
};