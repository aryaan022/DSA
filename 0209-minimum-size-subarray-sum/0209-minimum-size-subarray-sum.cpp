class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minl=INT_MAX;
        int l=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            while(sum>=target){
                minl=min(minl,i-l+1);
                sum=sum-nums[l];
                l++;
            }
        }
        if(minl==INT_MAX){
            return 0;
        }
        return minl;
    }
};