class Solution {
public:
    // bool isCycle(int src,vector<bool>&vis,vector<bool>&recpath,vector<vector<int>>&graph){
    //     vis[src]=true;
    //     recpath[src]=true;
    //     for(int i=0;i<graph.size();i++){
    //         int u=graph[i][1];
    //         int v=graph[i][0];
    //         if(u==src){
    //             if(!vis[v]){
    //                 if(isCycle(v,vis,recpath,graph)){
    //                     return  true;
    //                 }
    //             }
    //             else if(recpath[v]==true){
    //                 return true;
    //             }
    //         }
    //     }
    //     recpath[src]=false;
    //     return false;
    // }

    // void topoSort(int src,vector<bool>&vis,stack<int>&s,vector<vector<int>>& graph){
    //     vis[src]=true;
    //     for(int i=0;i<graph.size();i++){
    //         int u=graph[i][1];
    //         int v=graph[i][0];
    //         if(u==src){
    //             if(!vis[v]){
    //                 topoSort(v,vis,s,graph);
    //             }
                
    //         }
            
    //     }
    //     s.push(src);
    // }

    void calcuIndeg(vector<int>&indeg,vector<vector<int>>& graph){
        for(int i=0;i<graph.size();i++){
            int u=graph[i][1];
            int v=graph[i][0];

            indeg[v]++;
        }
        
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& graph) {
        
        // int v=numCourses;
        // vector<bool>vis(v,false);
        // vector<bool>recpath(v,false);
        // vector<int> ans;
        // for(int i=0;i<v;i++){
        //     if(!vis[i]){
        //         if(isCycle(i,vis,recpath,graph)){
        //             return ans;
        //         }
        //     }
        // }

        //topo sorting
        // stack<int>s; 
        // vector<bool>vis2(v,false);
        // for(int i=0;i<v;i++){
        //     if(!vis2[i]){
        //         topoSort(i,vis2,s,graph);
        //     }
        // }

        // while(!s.empty()){
        //     ans.push_back(s.top());
        //     s.pop();
        // }
        // return ans;




        int V=numCourses;
        vector<vector<int>>adj(V); 
        vector<int>ans;
        vector<int> indeg(V,0);
        queue<int>q;
        
        calcuIndeg(indeg,graph);

        for(auto p:graph){
            int u = p[1];
            int v = p[0];
            adj[u].push_back(v);
        }

        for(int i=0;i<V;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            for(int ne:adj[curr]){
                indeg[ne]--;
                if(indeg[ne]==0){
                    q.push(ne);
                }
            }
        }

        if(ans.size() != V){
            return {};
        }
        return ans;

    }
};