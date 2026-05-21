class Solution {
public:
    bool cycle(int src,vector<vector<int>>&graph,vector<bool>&vis,vector<bool>&recpath){
        vis[src]=true;
        recpath[src]=true;
        for(int i=0;i<graph.size();i++){
            int u= graph[i][1];
            int v=graph[i][0];
            if(u==src){
                if(!vis[v]){
                    if(cycle(v,graph,vis,recpath)){
                        return true;
                    }
                }
                else if(recpath[v]==true){
                    return true;
                }
            }
        }
        recpath[src]=false;
        return false;
    }


    bool canFinish(int numCourses, vector<vector<int>>& graph) {
        
        vector<bool> vis(numCourses,false); 
        vector<bool> recpath(numCourses,false); 

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(cycle(i,graph,vis,recpath)){
                    return false;
                }
            }
        }
        return true;
    }
};