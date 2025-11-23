class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int ac=0;
        int curr=0;
        int mis=0;
        for(int i =0;i<=n;i++){
            ac=ac+i;
        }
        for(int i=0;i<n;i++){
            curr=curr+nums[i];
        }
        mis=ac-curr;
        return mis;

    }
};