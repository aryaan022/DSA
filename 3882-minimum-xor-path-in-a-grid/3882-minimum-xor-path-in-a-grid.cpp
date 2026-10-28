class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        constexpr int MAX_XOR = 1024;

        vector<bitset<MAX_XOR>> dp(n);
        dp[0].set(grid[0][0]);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                bitset<MAX_XOR> reachable = dp[j];

                if (j > 0) {
                    reachable |= dp[j - 1];
                }

                bitset<MAX_XOR> next;
                int value = grid[i][j];

                for (int k = 0; k < MAX_XOR; k++) {
                    if (reachable[k]) {
                        next.set(k ^ value);
                    }
                }

                dp[j] = next;
            }
        }

        for (int k = 0; k < MAX_XOR; k++) {
            if (dp[n - 1][k]) {
                return k;
            }
        }

        return -1;
    }
};