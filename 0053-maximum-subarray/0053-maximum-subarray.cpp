class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=nums[0];
        int maxSum=nums[0];
        for(int i=1;i<nums.size();i++){
            currsum=max(nums[i],nums[i]+currsum);
            maxSum= max(maxSum,currsum);
        }
        return maxSum;
    }
};