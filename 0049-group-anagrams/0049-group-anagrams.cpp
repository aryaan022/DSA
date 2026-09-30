class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>result;
        if(strs.size()<=0){
            return result;

        }
        for(auto s:strs){
            string word=s;
            sort(word.begin(),word.end());
            mp[word].push_back(s);
        }
        for(auto it:mp){
            result.push_back(it.second);
        }

        return result;
        
    }
};