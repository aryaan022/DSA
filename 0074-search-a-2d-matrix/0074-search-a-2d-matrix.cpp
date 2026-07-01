class Solution {
public:
    bool bs(vector<int>arr,int t){
        int l=0;
        int h = arr.size()-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(arr[mid]==t){
                return true;
                break;
            }
            else if(arr[mid]>t){
                h=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool ans=false;
        for(int i=0;i<matrix.size();i++){
            ans =  bs(matrix[i],target);
            if(ans==true){
                break;
            }
        }
        return ans;
    }
};