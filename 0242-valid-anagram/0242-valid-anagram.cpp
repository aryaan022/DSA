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

        for(int j=0;j<t.size();j++)
        {
            if(!m.count(t[j])){
                return false;
            }
            m[t[j]]--;
            if(m[t[j]]==0){
                m.erase(t[j]);
            }
        }
        return m.empty();
    }
};