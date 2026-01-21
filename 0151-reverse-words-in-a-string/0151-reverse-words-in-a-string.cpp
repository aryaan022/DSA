class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string temp = "";

        // extract words
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                temp += s[i];
            } else {
                if (temp.length() > 0) {
                    words.push_back(temp);
                    temp = "";
                }
            }
        }

        // last word
        if (temp.length() > 0)
            words.push_back(temp);

        // build result in reverse order
        string ans = "";
        for (int i = words.size() - 1; i >= 0; i--) {
            ans += words[i];
            if (i != 0) ans += " ";
        }

        return ans;
    }
};
