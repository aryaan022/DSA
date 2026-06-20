class Solution {
public:
    bool cycle(int src, vector<bool>&recpath,vector<bool>&vis,vector<vector<int>>&graph){
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

    void toposort(int src,vector<bool>&vis,stack<int>&s,vector<vector<int>>&graph){
        vis[src]=true;
        for(int i=0;i<graph.size();i++){
            int u =graph[i][1];
            int v= graph[i][0];
            if(u==src){
                if(!vis[v]){
                    toposort(v,vis,s,graph);
                }
            }
        }
        s.push(src);
    }


    vector<int>findOrder(int numCourses, vector<vector<int>>&graph) {
        vector<bool>recpath(numCourses,false);
        vector<bool>vis(numCourses,false);
        vector<int>ans;

        for(int i =0;i<numCourses;i++){
            if(!vis[i]){
                if(cycle(i,recpath,vis,graph)){
                    return ans;
                }
            }
        }


        //performing topo sort now using DFS
        stack<int>s;
        vector<bool>vis2(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis2[i]){
                toposort(i,vis2,s,graph);
            }
        }

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
        

    }
};