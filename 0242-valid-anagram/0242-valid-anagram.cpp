class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>m;

        for(int i=0;i<s.size();i++){
            if(m.count(s[i])){
                m[s[i]]++;
            }
            else{
                m[s[i]]=1;
            }
        }

        for(int i=0;i<t.size();i++){
            if(!m.count(t[i])){
                return false;
            }
            m[t[i]]--;
            if(m[t[i]]==0){
                m.erase(t[i]);
            }
        }
        return m.empty();
    }
};