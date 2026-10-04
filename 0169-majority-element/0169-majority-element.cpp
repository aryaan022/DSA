class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int target=nums.size()/2;
        int ans=0;
        unordered_map<int,int>mp;
        for(auto n:nums){
            if(mp.count(n)){
                mp[n]++;
            }
            else{
                mp[n]=1;
            }
        }
        for(auto it:mp){
            if(it.second >target){
                return it.first;
            }
        }
        return 0;
    }
};