class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;//freq,number
        unordered_map<int,int>mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(!mp.count(nums[i])){
                mp[nums[i]]=1;
            }
            else{
                mp[nums[i]]++;
            }
        }
        for(auto it:mp){
            pq.push({it.second,it.first});
        }

        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};