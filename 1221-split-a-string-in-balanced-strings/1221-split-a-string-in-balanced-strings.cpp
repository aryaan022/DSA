class Solution {
public:
    int balancedStringSplit(string s) {
        int c=0;
        int ans=0;
        int n= s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                c++;
            }
            if(s[i]=='R'){
                c--;
            }
            if(c==0){
                ans++;
            }
        }
        return ans;
        
    }
};