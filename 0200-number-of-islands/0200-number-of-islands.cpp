class Solution {
public:
    void solve(int r,int c,vector<vector<char>>& grid,int n,int m){
        grid[r][c]=0;

        //up
        if(r-1>=0&&grid[r-1][c]=='1'){
            solve(r-1,c,grid,n,m);
        }

        //down
        if(r+1<n&&grid[r+1][c]=='1'){
            solve(r+1,c,grid,n,m);
        }

        //right
        if(c+1<m &&grid[r][c+1]=='1'){
            solve(r,c+1,grid,n,m);
        }

        //left
        if(c-1>=0 && grid[r][c-1]=='1'){
            solve(r,c-1,grid,n,m);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        int c=0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]=='1'){
                    solve(i,j,grid,n,m);
                    c +=1;
                }
            }

        }
        return c;
    }
};