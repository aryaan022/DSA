class Solution {
public: 
    void dfs(int row,int col,int n,int m,vector<vector<int>>& graph,int &count){
        if(row<0||row>=n||col<0||col>=m||graph[row][col]==0){
            return;
        }
        graph[row][col]=0;
        count ++;
        //up
        if(row-1>=0 &&  graph[row-1][col]==1){
            dfs(row-1,col,n,m,graph,count);
        }

        //down
        if(row+1<n && graph[row+1][col]==1){
            dfs(row+1,col,n,m,graph,count);
        }
        //left
        if(col-1>=0 && graph[row][col-1]==1){
            dfs(row,col-1,n,m,graph,count);
        }
        //right
        if(col+1<m&&graph[row][col+1]==1){
            dfs(row,col+1,n,m,graph,count);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        int maxCount =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(graph[i][j]==1){
                    int count =0;
                    dfs(i,j,n,m,graph,count);
                    maxCount =max(maxCount,count);
                }
            }
            
        }
        return maxCount;
    }
};