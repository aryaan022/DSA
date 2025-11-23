class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int res=0;
        sort(nums.begin(),nums.end());
        while(i<n){
            if(i==n-1){
                res=nums[i];
                break;
            }
            else if(nums[i]!=nums[i+1]){
                 res=nums[i];
                 break;
            }
            i=i+2;
        }
        return res;
    }
};