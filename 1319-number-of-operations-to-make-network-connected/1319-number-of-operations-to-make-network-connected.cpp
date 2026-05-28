class Solution {
public:
    vector<int>par;
    vector<int>rank;
    int find(int x){
        if(par[x]==x){
            return x;
        }
        return par[x]=find(par[x]);
    }

    void UnionByRank(int u, int v ,int &cycle)
    {
        int parU =find(u);
        int parV =find(v);

        if(parU == parV){
            cycle++;
            return;
        }
        if(rank[parU]==rank[parV]){
            par[parV]=parU;
            rank[parU]++;
        }
        else if(rank[parU]>rank[parV]){
            par[parV]=parU;
        }
        else{
            par[parU]=parV;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        int cycle=0;
        int comp=0;
        par.resize(n);
        rank.resize(n);

        for(int i=0;i<n;i++){
            par[i]=i;
            rank[i]=0;
        }

        for(auto e:connections){
            int u = e[0];
            int v = e[1];
            UnionByRank(u,v,cycle);
        }

        for(int i=0;i<n;i++){
            if(par[i]==i){
                comp++;
            }
        }

        if(cycle >= comp-1){
            return comp-1;
        }
        return -1;
    }
};