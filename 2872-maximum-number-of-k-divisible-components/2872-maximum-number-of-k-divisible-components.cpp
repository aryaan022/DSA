class Solution {
public:
    int ans = 0;
    
    long long dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& values, long long k){
        long long sum = values[node];   
        
        for(int child : adj[node]){
            if(child == parent) continue;
            
            long long childSum = dfs(child, node, adj, values, k);
            
            if(childSum % k == 0){
                ans++;
            } else {
                sum += childSum;   
            }
        }
        
        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1, adj, values, (long long)k);

        return ans + 1;
    }
};
