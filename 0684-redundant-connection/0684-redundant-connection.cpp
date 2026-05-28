class Solution {
public:
    vector<int>par;
    vector<int>rank;
    int find(int x){
        if(par[x]==x){
            return x;
        }
        return par[x]=find(par[x]); //[path compression]
    }

    void UnionByRank(int u,int v,vector<int>&ans){
        int ParU=find(u);
        int ParV=find(v);

        if(ParU == ParV){ //find the cycle one edge
            ans.push_back(u);
            ans.push_back(v);
            return;
        }
        if(rank[ParU]==rank[ParV]){
            par[ParV]=par[ParU];
            rank[ParU]++;
        }
        
        else if(rank[ParU]>rank[ParV]){
            par[ParV]=ParU;
        }
        else{
            par[ParU]=ParV;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        vector<int>ans;
        par.resize(n+1);
        rank.resize(n+1);

        for(int i=0;i<n+1;i++){
            par[i]=i;
            rank[i]=0;
        }

        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            UnionByRank(u,v,ans);
        }
        return ans;
    }
};