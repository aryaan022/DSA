class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++) {

            bool already = false;
            for(int a = 0; a < ans.size(); a++) {
                if(ans[a] == nums[i]) {
                    already = true;
                    break;
                }
            }
            if(already) continue;

            int count = 0;

            for(int j = 0; j < n; j++) {
                if(nums[i] == nums[j]) {
                    count++;
                }
            }

            if(count > n/3) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};
