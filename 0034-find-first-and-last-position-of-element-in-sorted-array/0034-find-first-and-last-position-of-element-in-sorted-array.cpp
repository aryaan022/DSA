class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return {-1, -1};
        }
        int first =-1;
        int last =-1;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                if(first==-1){
                    first=i;
                }
                last =i;
            }
        }
        if(first==-1){
            return{-1,-1};
        }
        return{first,last};
    }
};