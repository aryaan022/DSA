class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxf=0;
        int maxl=0;
        unordered_map<char,int>freq;
        int l=0;
        for(int j=0;j<s.size();j++){
            freq[s[j]]++;
            maxf=max(maxf,freq[s[j]]);
            while((j-l+1)-maxf>k){
                freq[s[l]]--;
                l++;
            }
            maxl=max(maxl,(j-l+1));
        }
        return maxl;
    }
};