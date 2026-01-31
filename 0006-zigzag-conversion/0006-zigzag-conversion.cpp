class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>rows(numRows);
        if (numRows == 1 || s.size() <= numRows)
            return s;
        int dir=-1;
        int curr=0;
        for(int i =0;i<s.size();i++){
            rows[curr]=rows[curr]+s[i];
            if(curr==0){
                dir=1;
            }
            else if(curr==numRows-1){
                dir=-1;
            }
            curr=curr+dir;
        }
        string ans = "";
        for (int i = 0; i < numRows; i++) {
            ans += rows[i];
        }
        return ans;
    }
};