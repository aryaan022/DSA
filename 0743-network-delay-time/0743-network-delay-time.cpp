class Solution {
public: 
    void dij(int src,vector<int>&dist,vector<vector<pair<int,int>>>&graph){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; //min heap wt[v] , v
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int u=pq.top().second;
            pq.pop();
            for(auto e:graph[u]){
                int wt= e.first;
                int v = e.second;

                if(dist[v]>dist[u]+wt){
                    dist[v]=dist[u]+wt;
                    pq.push({dist[v],v});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);
        int ans=INT_MIN;
        vector<vector<pair<int,int>>>graph(n+1);

        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int wt=times[i][2];
            graph[u].push_back({wt,v});
        }
        dij(k,dist,graph);

        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};