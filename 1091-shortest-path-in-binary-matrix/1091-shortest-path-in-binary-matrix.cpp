class Solution {
public:
    int cal(int row,int col,int m ,int n,vector<vector<int>>& g){
        if(g[row][col]!=0){
            return -1;
        }
        
        g[row][col]=1;
        int count=1;
        queue<pair<int,int>>q;
        q.push(make_pair(row,col));
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                pair<int,int>curr= q.front();
                q.pop();
                int r=curr.first;
                int c= curr.second;
                if(r==m-1 &&c==n-1){
                    return count;
                }
                // Up
                if (r-1 >= 0 && g[r-1][c] == 0) {
                   g[r-1][c] = 1;
                    q.push({r-1, c});
                }

                // Down
                if (r+1 < m && g[r+1][c] == 0) {
                    g[r+1][c] = 1;
                    q.push({r+1, c});
                }

                // Left
                if (c-1 >= 0 && g[r][c-1] == 0) {
                    g[r][c-1] = 1;
                    q.push({r, c-1});
                }

                // Right
                if (c+1 < n && g[r][c+1] == 0) {
                    g[r][c+1] = 1;
                    q.push({r, c+1});
                }

                // Top Left
                if (r-1 >= 0 && c-1 >= 0 && g[r-1][c-1] == 0) {
                    g[r-1][c-1] = 1;
                    q.push({r-1, c-1});
                }

                // Top Right
                if (r-1 >= 0 && c+1 < n && g[r-1][c+1] == 0) {
                    g[r-1][c+1] = 1;
                    q.push({r-1, c+1});
                }

                // Bottom Left
                if (r+1 < m && c-1 >= 0 && g[r+1][c-1] == 0) {
                    g[r+1][c-1] = 1;
                    q.push({r+1, c-1});
                }

                // Bottom Right
                if (r+1 < m && c+1 < n && g[r+1][c+1] == 0) {
                    g[r+1][c+1] = 1;
                    q.push({r+1, c+1});
                }
                
            }
            count++;
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        return cal(0,0,m,n,g);
    }
};