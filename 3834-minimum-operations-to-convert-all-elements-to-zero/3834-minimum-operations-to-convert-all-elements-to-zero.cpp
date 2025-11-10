class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> st;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                st.clear();
                continue;
            }
            int x = nums[i];
            if (st.empty() || st.back() < x) {
                st.push_back(x);
                ++ans;
            } else if (st.back() == x) {
                continue;
            } else {
                while (!st.empty() && st.back() > x) st.pop_back();
                if (st.empty() || st.back() < x) {
                    st.push_back(x);
                    ++ans;
                }
            }
        }
        return ans;
    }
};
