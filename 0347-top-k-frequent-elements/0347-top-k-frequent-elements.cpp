class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>> freq;
        int count =1;
        vector<int> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                count ++;
            }
            else{
                freq.push_back({count,nums[i-1]});
                count=1;
            }
        }
        freq.push_back({count,nums[n-1]});
        sort(freq.rbegin(), freq.rend());

        for(int i=0;i<k;i++){
            ans.push_back(freq[i].second);
        }
        return ans;
    }
};