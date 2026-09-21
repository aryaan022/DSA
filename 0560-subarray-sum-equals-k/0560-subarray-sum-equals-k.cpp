class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int rs=0;
        int c=0;

        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            rs = rs+nums[i];
            int cs=rs-k;

            if(mp.find(cs)!=mp.end()){
                c =c+mp[cs];
            }
            mp[rs]++;

        }
        return c;
    }
};