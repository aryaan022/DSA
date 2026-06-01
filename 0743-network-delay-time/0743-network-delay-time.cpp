class Solution {
public:
    void dij(int src,int V,vector<int>&dist,vector<vector<pair<int,int>>>&graph){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; //wt[v],v
        dist[src]=0;
        pq.push(make_pair(0,src));
        while(!pq.empty()){
            int u=pq.top().second;
            pq.pop();
            for(auto e:graph[u]){
                int v=e.first;
                int wt=e.second;
                if(dist[v]>dist[u]+wt){
                    dist[v]=dist[u]+wt;
                    pq.push({dist[v],v}); //pushing the distance[v] and the vertex
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //step 1 build gaph and push value for u , v and wt
        vector<vector<pair<int,int>>>graph(n+1);
        vector<int>dist(n+1,INT_MAX);
        int ans=INT_MIN;
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int wt=times[i][2];
            graph[u].push_back(make_pair(v,wt));
        }
        dij(k,n,dist,graph);
        for(int i=1;i<=n;i++){ // why 1 because we ar enot use index 0 as the elemt in grpah is from 1 to n this time
            if(dist[i]==INT_MAX){
                return -1;
            }
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};