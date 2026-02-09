class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size()-1;
        string ans="";
        int i=n;
        for(;i>=0;i--){
            if(num[i]%2!=0){
                break;
            }
        }
        for (int j =0;j<=i;j++){
            ans.push_back(num[j]);
        }
        return ans;
        
    }
};