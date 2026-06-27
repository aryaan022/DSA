class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n=m.size();

        //step 1 to transpose the matrix
        for(int i=0;i<n;i++){
            for(int j =i+1;j<n;j++){
                swap(m[i][j],m[j][i]);
            }
        }
        //step 2 - to reverse the every row
        for(int i=0;i<n;i++){
            int l=0;int r=n-1;
            while(l<r){
                swap(m[i][l],m[i][r]);
                l++;
                r--;
            }

        }


    }
};