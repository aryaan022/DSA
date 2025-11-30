class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums) total += x;

        int rem = total % p;
        if (rem == 0) return 0;

        unordered_map<int, int> lastIndex;
        lastIndex[0] = -1;

        long long prefix = 0;
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) {

            prefix = (prefix + nums[i]) % p;

            int need = (prefix - rem + p) % p;

            if (lastIndex.count(need)) {
                int len = i - lastIndex[need];
                if (len < ans) ans = len;
            }

            lastIndex[prefix] = i;
        }

        return ans == nums.size() ? -1 : ans;
    }
};
