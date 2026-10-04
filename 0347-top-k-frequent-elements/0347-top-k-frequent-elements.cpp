class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>> pq;
        vector<int>ans;
        for(auto n:nums){
            if(mp.count(n)){
                mp[n]++;
            }
            else{
                mp[n]=1;
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