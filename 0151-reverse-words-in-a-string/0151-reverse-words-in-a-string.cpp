class Solution {
public:
    string reverseWords(string s) {
        vector<string>word;
        string t="";
        for(int i =0;i<s.length();i++){
            if(s[i]!=' '){
                t =t+s[i];
            }
            else if(t.length()>0){
                word.push_back(t);
                t="";
            }
        }

        if(t.length()>0){
            word.push_back(t);
        }
        string ans="";

        for(int i=word.size()-1;i>=0;i--){
            ans=ans+word[i];
            if(i>0){
                ans=ans+" ";
            }
        }
        return ans;
        
    }
};