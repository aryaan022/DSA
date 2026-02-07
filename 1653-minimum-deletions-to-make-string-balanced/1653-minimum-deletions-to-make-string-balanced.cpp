class Solution {
public:
    int minimumDeletions(string s) {
        int c=0;
        int res=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b'){
                c++;
            }
            else if(s[i]=='a'){
                if(c>0){
                    res++;
                    c--;
                }
            }
        }
        return res;
    }
};