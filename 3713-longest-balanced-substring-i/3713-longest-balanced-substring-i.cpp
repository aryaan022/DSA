class Solution {
public:
    int longestBalanced(string s) {
        int maxlen =0;
        int n = s.size();
        for(int i=0;i<n;i++){
            int l=0;
            vector<int> freq(26,0);
            for(int j =i;j<n;j++){
                int idx=s[j]-'a';
                freq[idx]++;
                int mini=INT_MAX;
                int maxi=INT_MIN;
                for(int k =0;k<26;k++){
                    if(freq[k]>0){
                        mini=min(mini,freq[k]);
                        maxi=max(maxi,freq[k]);
                    }
                }
                if(mini==maxi){
                    maxlen=max(maxlen,j-i+1);
                }

            }
        }
        return maxlen;
    }
};