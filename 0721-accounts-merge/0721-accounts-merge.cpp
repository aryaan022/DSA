class Solution {
public:
    vector<int>rank;
    vector<int>par;
    int find(int x){
       if(par[x]==x){
            return x;
       }
       return par[x]=find(par[x]);
    }

    void UnionByRank(int u,int v){
        int ParU = find(u);
        int ParV=find(v);

        if(ParU==ParV){
            return;
        }
        if(rank[ParU]==rank[ParV]){
            par[ParV]=ParU;
            rank[ParU]++;
        }
        else if(rank[ParU]>rank[ParV]){
            par[ParV]=ParU;
        }
        else{
            par[ParU]=ParV;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        rank.resize(n);
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
            rank[i]=0;
        }

        //findig duplicate
        unordered_map<string,int>m;
        for (int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(m.count(accounts[i][j])){
                    UnionByRank(i,m[accounts[i][j]]);
                }
                else{
                    m[accounts[i][j]]=i;
                }
            }
        }

        unordered_map<int ,vector<string>>mp;
        for(auto it:m){
            string email=it.first;
            int idx= it.second;

            int updatedidx=find(idx);
            mp[updatedidx].push_back(email);
        }


        vector<vector<string>>ans;

        for(auto it:mp){
            vector<string>temp;
            int idx=it.first;
            vector<string>email =it.second;
            string name = accounts[idx][0];
            sort(email.begin(),email.end());
            temp.push_back(name);
            for(auto e:email){
                temp.push_back(e);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};