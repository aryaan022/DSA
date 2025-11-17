class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int Last =-1;
        for(int i =0;i<nums.size();i++){
            if(nums[i]==1){
                if(Last!=-1 &&  i-Last-1<k ){
                    return false;
                }
                Last =i;
            }
        }
        return true;
    }
};