class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result(numRows);

        for(int i =0;i<numRows;i++){
            vector<int>row;
            row.push_back(1);
            for(int j=1;j<i;j++){
               int v=result[i-1][j]+result[i-1][j-1];
                row.push_back(v);
            }
            if(i>0){
                row.push_back(1);
            }
            result[i]=row;
        }
        

        return result;
    }
};