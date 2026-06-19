class Solution {
public:
    vector<vector<string>>ans;
    bool isPal(string s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void solve(int st,string &s,vector<string>&temp,vector<vector<string>>&ans){
        if(st==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int j =st;j<s.size();j++){
            if(isPal(s,st,j)){
                temp.push_back(s.substr(st,j-st+1));
                solve(j+1,s,temp,ans);
                temp.pop_back(); //backtracking ke wakt remove kr dega
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        solve(0,s,temp,ans);
        return ans;
    }
};