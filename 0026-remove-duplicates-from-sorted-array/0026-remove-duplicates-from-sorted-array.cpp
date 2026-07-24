class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int s=0;
        for(int j =1;j<nums.size();j++){
            if(nums[s]!=nums[j]){
                s++;
                nums[s]=nums[j];
            }
        }
        return s+1;
    }
};