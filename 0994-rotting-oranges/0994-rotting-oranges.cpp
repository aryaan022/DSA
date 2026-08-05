class Solution {
public:
    void bfs(int m ,int n,vector<vector<int>>& g,int &c){
        queue<pair<int,int>>q;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(g[i][j]==2){
                    q.push(make_pair(i,j));
                }
            }
        }
        while(!q.empty()){
            int s=q.size();
            for(int i =0;i<s;i++){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();

                //up
                if(r-1>=0 &&g[r-1][c]==1){
                    g[r-1][c]=2;
                    q.push({r-1,c});
                }
                //down
                if(r+1<m && g[r+1][c]==1){
                    g[r+1][c]=2;
                    q.push({r+1,c});
                }
                //right
                if(c+1<n && g[r][c+1]==1){
                    g[r][c+1]=2;
                    q.push({r,c+1});
                }

                //left
                if(c-1>=0 && g[r][c-1]==1){
                    g[r][c-1]=2;
                    q.push({r,c-1});
                }
            }
            if(!q.empty()){
                c++;
            }
        }
    }
    int orangesRotting(vector<vector<int>>& g) {
        int  count=0;
        int m =g.size();
        int n = g[0].size();
        bfs(m,n,g,count);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]==1){
                    return -1;
                }
            }
        }
        return count;
    }
};