class Solution {
public:
    void dfs(int src,vector<vector<int>>& isConnected,vector<bool>&vis){
        vis[src]=true;
        for(int j=0;j<isConnected.size();j++){
            if(isConnected[src][j]==1 && !vis[j]){
                dfs(j,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<bool> vis(v,false);
        int count =0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                count++;
                dfs(i,isConnected,vis);
            }
        }
        return count;
    }
};