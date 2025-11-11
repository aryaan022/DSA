
class Solution {
public:
    bool can(const vector<long long>& basePower, int r, long long k, long long target) {
        int n = basePower.size();
        vector<long long> diff(n + 1, 0);
        long long window = 0;
        for (int i = 0; i < n; ++i) {
            window += diff[i];
            long long have = basePower[i] + window;
            if (have < target) {
                long long need = target - have;
                if (need > k) return false;
                k -= need;
                int p = min(n - 1, i + r);
                int left = max(0, p - r);
                int right = min(n - 1, p + r);
                diff[left] += need;
                diff[right + 1] -= need;
                window += need;
            }
        }
        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> prefix(n + 1, 0), basePower(n, 0);
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + stations[i];
        for (int i = 0; i < n; ++i) {
            int L = max(0, i - r), R = min(n - 1, i + r);
            basePower[i] = prefix[R + 1] - prefix[L];
        }
        long long low = 0, high = accumulate(stations.begin(), stations.end(), 0LL) + k, ans = 0;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (can(basePower, r, k, mid)) ans = mid, low = mid + 1;
            else high = mid - 1;
        }
        return ans;
    }
};






