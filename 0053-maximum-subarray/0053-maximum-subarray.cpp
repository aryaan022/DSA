class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= nums.size();
        int maxsum=INT_MIN;
        int curr= 0;
        for(int i=0;i<n;i++){
            curr=curr+nums[i];
            maxsum=max(maxsum,curr);
            if(curr<0){
                curr=0;
            }
        }
        return maxsum;
    }
};