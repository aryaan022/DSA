class Solution {
public:
    bool cycle(int src,vector<vector<int>>&graph,vector<bool>&vis,vector<bool>&recpath){
        vis[src]=true;
        recpath[src]=true;

        for(int v:graph[src]){
            if(!vis[v]){
                if(cycle(v,graph,vis,recpath)){
                    return true;
                }
            }
            else if(recpath[v]==true){
                return true;
            }
        }
        recpath[src]=false;
        return false;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>>graph(numCourses);

        for(auto p:prerequisites){
            int x=p[0];
            int y=p[1];
            graph[y].push_back(x);
        }

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