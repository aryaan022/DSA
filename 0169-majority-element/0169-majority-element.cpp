class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])){
                mp[nums[i]]++;
            }
            else{
                mp[nums[i]]=1;
            }
        }

        for(pair<int,int>p:mp){
            if(p.second>nums.size()/2){
                ans= p.first;
            }
        }
        return ans;
    }
};