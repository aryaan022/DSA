class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V= graph.size();
        vector<int>c(V,-1);
        queue<int>q;
        for(int i=0;i<V;i++){
            if(c[i]==-1){
                q.push(i);
                c[i]=0;
                while(!q.empty()){
                    int u =q.front();
                    q.pop();
                    for(auto ne : graph[u]){
                        if(c[ne]==-1){
                            c[ne]=!c[u];
                            q.push(ne);
                        }
                        else if(c[ne]==c[u]){
                            return  false;
                        }
                    }
                }
            }
        }
        return true;
        
    }
};