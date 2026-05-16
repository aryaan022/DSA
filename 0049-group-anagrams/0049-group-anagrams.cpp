class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>m;
        vector<vector<string>>ans;
        if(strs.size()==0){
            return ans;
        }

        for(auto it:strs){
            //sort i
            string w=it;
            sort(w.begin(),w.end());
            m[w].push_back(it);
        }

        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
        
    }
};