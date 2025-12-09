class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1000000007;
        unordered_map<long long, long long> leftFreq, rightFreq;

        for (int x : nums) rightFreq[x]++;

        long long ans = 0;

        for (int j = 0; j < (int)nums.size(); j++) {
            long long v = nums[j];
            rightFreq[v]--;

            long long target = v * 2;
            ans = (ans + (leftFreq[target] * rightFreq[target]) % MOD) % MOD;

            leftFreq[v]++;
        }

        return (int)(ans % MOD);
    }
};
