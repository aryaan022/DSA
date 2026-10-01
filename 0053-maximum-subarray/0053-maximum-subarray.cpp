class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cs=0;
        int maxsum=INT_MIN;
        for(auto n:nums){
            cs=cs+n;
            cs=max(cs,n);
            maxsum=max(maxsum,cs);
        }
        return maxsum;
    }
};