class Solution {
public:
    vector<int>rank;
    vector<int>Par;
    int find(int x){
        if(Par[x]==x){
            return x;
        }
        return Par[x]=find(Par[x]); //path compression
    }

    void UnionByRank(int u,int v){
        int ParU = find(u);
        int ParV=find(v);

        if(ParU==ParV){
            return;
        }
        if(rank[ParU]==rank[ParV]){
            Par[ParV]=ParU;
            rank[ParU]++;
        }
        else if(rank[ParU]>rank[ParV]){
            Par[ParV]=ParU;
        }
        else{
            Par[ParU]=ParV;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // reinitialise
        int n = accounts.size();
        rank.resize(n);
        Par.resize(n);
        for(int i=0;i<n;i++){
            Par[i]=i;
            rank[i]=0;
        }


        //2 unordered map me email and uska index store krege for finding dupplicate
        unordered_map<string,int>m;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(m.count(accounts[i][j])){
                    UnionByRank(i,m[accounts[i][j]]);
                }
                else{
                    m[accounts[i][j]]=i;
                }
            }
        }

        //3  finding original parents for emails and string them into map
        unordered_map<int,vector<string>>mp;
        for(auto it :m){
            string email = it.first;
            int idx=it.second;

            int originalidx= find(idx);
            mp[originalidx].push_back(email);  // basically it will look like  0 ->{ar@gmail.com , br@gmail.com} 
        }

        //4 last phase ab humko name uthana original se and emails uthani mp se and merge karke array me add krna and return krna hai
        vector<vector<string>>ans;
        
        for(auto  it:mp){
            vector<string>temp;
            int idx = it.first;
            vector<string>emails =it.second;
            string name=accounts[idx][0];
            sort(emails.begin(),emails.end());
            temp.push_back(name);
            for(auto e:emails){
                temp.push_back(e);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};