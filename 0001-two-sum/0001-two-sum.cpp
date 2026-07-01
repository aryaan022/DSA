class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            int w= target-nums[i];
            if(m.count(w)){
                return {m[w],i};
                break;
            }
            m[nums[i]]=i;
        }
        return{};
    }
};