class Solution {
public:
    bool isCycle(int src,vector<bool>&recpath,vector<bool>&isvis , vector<vector<int>>& graph){
        recpath[src]=true;
        isvis[src]=true;

        for(int i=0;i<graph.size();i++){
            int u = graph[i][1];
            int v = graph[i][0];

            if(u==src){
                if(!isvis[v]){
                    if(isCycle(v,recpath,isvis,graph)){
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
        vector<bool>recpath(numCourses,false);
        vector<bool>isvis(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!isvis[i]){
                if(isCycle(i,recpath,isvis,graph)){
                    return false;
                }
            }
        }
        return true;
    }
};