class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // ans[i] = (product on left * product of right
        int left=1;
        int right=1;
        vector<int> ans(nums.size(),1);

        //calculating left
        for(int i=0;i<nums.size();i++){
            ans[i]=ans[i]*left;
            left=nums[i]*left;
        }
        //calculating right and merging it wuth ans that is ans[i]*right and what is ans[i] it is left so basically left*right
        for(int i=nums.size()-1;i>=0;i--){
            ans[i]=ans[i]*right;
            right=nums[i]*right;
        }
        return ans;
     }
};