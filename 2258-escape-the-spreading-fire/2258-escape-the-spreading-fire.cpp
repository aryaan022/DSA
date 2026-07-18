class Solution {
public:
    void firebfs(vector<vector<int>>&g,vector<vector<int>>&t){
        queue<pair<int,int>>q;
        int m =g.size();
        int n =g[0].size();
        //pushing all the fire points into the queue
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]==1){
                    q.push(make_pair(i,j));
                    t[i][j]=0;
                }
            }
        }
        //now explorign neghobours of it
        while(!q.empty()){
            pair<int,int>curr =q.front();
            q.pop();
            int r=curr.first;
            int c= curr.second;
            //up
            if(r-1>=0 && g[r-1][c]!=2 && t[r-1][c]==INT_MAX){
                t[r-1][c]=t[r][c]+1;
                q.push(make_pair(r-1,c));
            }
            //down
            if(r+1<m && g[r+1][c]!=2 && t[r+1][c]==INT_MAX){
                t[r+1][c]=t[r][c]+1;
                q.push(make_pair(r+1,c));
            }
            //left
            if(c-1>=0 && g[r][c-1]!=2 && t[r][c-1]==INT_MAX){
                t[r][c-1]=t[r][c]+1;
                q.push(make_pair(r,c-1));
            }
            //right
            if(c+1<n && g[r][c+1]!=2 && t[r][c+1]==INT_MAX){
                t[r][c+1]=t[r][c]+1;
                q.push(make_pair(r,c+1));
            }

        }
    }

    //is wait can reach to the fire time
    bool canReach(int wait,vector<vector<int>>&g,vector<vector<int>>&ft){

        if(wait>=ft[0][0]){
            return false;
        }
        int m =g.size();
        int n =g[0].size();
        vector<vector<int>>at(m, vector<int>(n, INT_MAX));
        queue<pair<int,int>>q;
        at[0][0]=wait;
        q.push(make_pair(0,0));
        while(!q.empty()){
            pair<int,int>curr=q.front();
            q.pop();
            int r=curr.first;
            int c=curr.second;
            if(r == m-1 && c == n-1){
                return true;
            }

            if(r-1>=0 && g[r-1][c] == 0 && at[r-1][c] == INT_MAX)
            {
                int nt=at[r][c] + 1;

                if((r-1 == m-1 && c == n-1 && nt <= ft[r-1][c])||(r-1 != m-1 || c != n-1) && nt < ft[r-1][c])
                {
                    at[r-1][c] = nt;
                    q.push(make_pair(r-1,c));
                }   
            }
            if(r+1<m && g[r+1][c]==0 && at[r+1][c]==INT_MAX){
                int nt=at[r][c]+1;
                if((r+1==m-1 && c==n-1 && nt<=ft[r+1][c])||(r+1!=m-1 || c!=n-1)&& nt<ft[r+1][c]){
                    at[r+1][c]=nt;
                    q.push(make_pair(r+1,c));
                }
            }
            if(c-1>=0 && g[r][c-1]==0 &&at[r][c-1]==INT_MAX){
                int nt = at[r][c]+1;
                if((r==m-1 && c-1 ==n-1 && nt<=ft[r][c-1])||(r!=m-1 || c-1!=n-1)&&nt<ft[r][c-1]){
                    at[r][c-1]=nt;
                    q.push(make_pair(r,c-1));
                }
                
            }
            if(c+1<n && g[r][c+1]==0 &&  at[r][c+1]==INT_MAX){
                int nt = at[r][c]+1;
                if((r==m-1 && c+1 ==n-1 && nt<=ft[r][c+1])||(r!=m-1 ||c+1!=n-1)&&nt<ft[r][c+1]){
                    at[r][c+1]=nt;
                    q.push(make_pair(r,c+1));
                }
            }

            
        }
        return false;

    }
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>>firetime(m,vector<int>(n,INT_MAX));
        firebfs(grid,firetime);
        int l=0;
        int h= 1000000000;
        int ans=-1;
        while(l<=h){
            int m = l+(h-l)/2;
            if(canReach(m,grid,firetime)){
                ans=m;
                l=m+1;
            }else{
                h=m-1;
            }
        }
        return ans;

    }
};