class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int k=0;
        int n= nums.size();
        for(int i=0;i<n;i++){
            k=target-nums[i];
            for(int j=i+1;j<n;j++){
                if(nums[j]==k){
                    return{i,j};
                }
            }
        }
        return {};
        
    }
};