class Solution {
public:
    bool cycle(int src, vector<bool>&recpath,vector<bool>&vis,vector<vector<int>>& graph){
        vis[src]=true;
        recpath[src]=true;
        for(int i=0;i<graph.size();i++){
            int u = graph[i][1];
            int v = graph[i][0];
            if(u==src){
                if(!vis[v]){
                    if(cycle(v,recpath,vis,graph)){
                        return true;
                    }
                }
                else if(recpath[v]){
                    return true;
                }
            }
        }
        recpath[src]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& graph) {

        vector<bool>vis(numCourses,false);
        vector<bool>recpath(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(cycle(i,recpath,vis,graph)){
                    return false;
                }
            }
        }
        return true;
    }
};