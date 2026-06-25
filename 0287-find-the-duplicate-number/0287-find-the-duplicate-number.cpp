class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>m;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(m.count(nums[i])){
                ans= nums[i];
                break;
                
            }
            else{
                m[nums[i]]=1;
            }
        }
        return ans;

    }
};