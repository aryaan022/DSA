class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int len = s.size();
        int i = len - 2;
        while (i >= 0 && s[i] >= s[i + 1]) {
            i--;
        }
        if (i < 0) return -1;
        int j = len - 1;
        while (s[j] <= s[i]) {
            j--;
        }
        swap(s[i], s[j]);
        reverse(s.begin()+i+1, s.end());
        long long ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans = ans * 10 + (s[i] - '0');
        }

        if (ans > INT_MAX) {
            return -1;
        } else {
            return (int)ans;
        }

    }
};
