class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int num = 0;
        for(int bit : nums) {
            num = (num * 2 + bit) % 5;
            ans.push_back(num == 0);
        }
        return ans;
    }
};
