class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>result;
        if(matrix.empty()){

            return result;
        }
        int m = matrix.size();
        int n = matrix[0].size();

        int t=0;
        int b=m-1;
        int l=0;
        int r=n-1;

        while(t<=b && l<=r){
            for(int j=l;j<=r;j++){
                result.push_back(matrix[t][j]);
            }
            t++;
            for(int i=t;i<=b;i++){
                result.push_back(matrix[i][r]);
            }
            r--;
            if(t<=b){
                for(int j=r;j>=l;j--){
                    result.push_back(matrix[b][j]);
                }
                b--;
            }
            if(l<=r){
                for(int i=b;i>=t;i--){
                    result.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        return result;
    }
};