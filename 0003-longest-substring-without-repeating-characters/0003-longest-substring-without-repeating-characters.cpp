class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string a = "";
        int maxLen = 0;

        for (int i = 0; i < s.length(); i++) {

            int pos = a.find(s[i]);
            if (pos != string::npos) {
                a = a.substr(pos + 1);
            }

            a += s[i];
            maxLen = max(maxLen, (int)a.length());
        }

        return maxLen;
    }
};
