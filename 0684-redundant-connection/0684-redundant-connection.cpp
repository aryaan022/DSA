class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }

    void unionByRank(int u,int v,vector<int>&ans){
        int ParU= find(u);
        int ParV=find(v);
        if(ParU==ParV){
            ans.push_back(u);
            ans.push_back(v);
            return;
        }

        if(rank[ParU]==rank[ParV]){
            parent[ParV]=ParU;
            rank[ParU]++;
        }
        else if(rank[ParU]>rank[ParV]){
            parent[ParV]=ParU;
        }
        else{
            parent[ParU]=ParV;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
        vector<int>ans;
        for(int i =0;i<edges.size();i++){
            int u =edges[i][0];
            int v =edges[i][1];
            unionByRank(u,v,ans);
        }
        return ans;
    }
};