class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int maxl=0;
        unordered_set<char>st;
        while(r<s.size()){
            char ch =s[r];
            if(st.find(ch)==st.end()){
                st.insert(ch);
            }
            else{
                while(st.find(ch)!=st.end()){
                    st.erase(s[l]);
                    l++;
                }
                st.insert(ch);
            }
            maxl=max(maxl,r-l+1);
            r++;
        }
        return maxl;
    }
};