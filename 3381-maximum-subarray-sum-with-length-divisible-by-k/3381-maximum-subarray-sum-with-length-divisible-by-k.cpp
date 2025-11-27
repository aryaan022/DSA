class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> best(k, LLONG_MAX);
        
        long long pref = 0;
        long long ans = LLONG_MIN;
        
        best[0] = 0; 
        
        for (int i = 0; i < n; i++) {
            pref += nums[i];
            int mod = (i + 1) % k;
            
            if (best[mod] != LLONG_MAX) {
                ans = max(ans, pref - best[mod]);
            }
            
            best[mod] = min(best[mod], pref);
        }
        
        return ans;
    }
};
