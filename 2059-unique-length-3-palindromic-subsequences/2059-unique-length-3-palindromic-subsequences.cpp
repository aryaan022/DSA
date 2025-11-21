class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();

        vector<int> first(26, -1);
        vector<int> last(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - '0';  
        }

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        int ans = 0;

        for (int x = 0; x < 26; x++) {
            if (first[x] == -1 || last[x] - first[x] < 2) continue;

            vector<bool> seen(26, false);

            for (int i = first[x] + 1; i < last[x]; i++) {
                seen[s[i] - 'a'] = true;
            }

            for (int y = 0; y < 26; y++) {
                if (seen[y]) ans++;
            }
        }

        return ans;
    }
};
