class Solution {
public:
    long long numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> zeros;
        for (int i = 0; i < n; ++i) if (s[i] == '0') zeros.push_back(i);
        zeros.push_back(n);
        int zcnt = (int)zeros.size() - 1;
        long long ans = 0;
        int limit = sqrt(n) + 1;
        for (int l = 0; l < n; ++l) {
            int idx = lower_bound(zeros.begin(), zeros.begin() + zcnt, l) - zeros.begin();
            int nextZero = zeros[idx];
            ans += nextZero - l;
            for (int z = 1; z <= limit; ++z) {
                if (idx + z - 1 >= zcnt) break;
                int r_min = zeros[idx + z - 1];
                int r_max = zeros[(idx + z) <= zcnt ? idx + z : zcnt] - 1;
                long long need = 1LL * l + z + 1LL * z * z - 1;
                int r_need = (int)max<long long>(r_min, need);
                if (r_need <= r_max) ans += (r_max - r_need + 1);
            }
        }
        return ans;
    }
};
