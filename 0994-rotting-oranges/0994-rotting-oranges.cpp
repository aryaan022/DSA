class Solution {
public:
    void bfs(int n,int m,vector<vector<int>>& grid,int &count){
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push(make_pair(i,j));
                }
            }
        }

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();

                //dowm
                if(row+1<n && grid[row+1][col]==1){
                    grid[row+1][col]=2;
                    q.push(make_pair(row+1,col));
                }

                //up
                if(row-1>=0 && grid[row-1][col]==1){
                    grid[row-1][col]=2;
                    q.push(make_pair(row-1,col));
                }

                //left
                if(col-1>=0 && grid[row][col-1]==1){
                    grid[row][col-1]=2;
                    q.push(make_pair(row,col-1));
                }

                //right
                if(col+1<m && grid[row][col+1]==1){
                    grid[row][col+1]=2;
                    q.push(make_pair(row,col+1));
                }
            }
            if(!q.empty()){   
                count++;
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count =0;
        bfs(n,m,grid,count);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return count;
    }
};