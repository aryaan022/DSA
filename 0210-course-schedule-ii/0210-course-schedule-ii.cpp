class Solution {
public:
    bool isCycle(int src,vector<bool>&vis,vector<bool>&recpath,vector<vector<int>>&graph){
        vis[src]=true;
        recpath[src]=true;
        for(int i=0;i<graph.size();i++){
            int u=graph[i][1];
            int v=graph[i][0];
            if(u==src){
                if(!vis[v]){
                    if(isCycle(v,vis,recpath,graph)){
                        return  true;
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

    void topoSort(int src,vector<bool>&vis,stack<int>&s,vector<vector<int>>& graph){
        vis[src]=true;
        for(int i=0;i<graph.size();i++){
            int u=graph[i][1];
            int v=graph[i][0];
            if(u==src){
                if(!vis[v]){
                    topoSort(v,vis,s,graph);
                }
                
            }
            
        }
        s.push(src);
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& graph) {
        int v=numCourses;
        vector<bool>vis(v,false);
        vector<bool>recpath(v,false);
        vector<int> ans;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(isCycle(i,vis,recpath,graph)){
                    return ans;
                }
            }
        }

        //topo sorting
        stack<int>s; 
        vector<bool>vis2(v,false);
        for(int i=0;i<v;i++){
            if(!vis2[i]){
                topoSort(i,vis2,s,graph);
            }
        }

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};