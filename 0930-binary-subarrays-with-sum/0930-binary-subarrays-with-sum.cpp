class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
    if (goal < 0) {
        return 0;
    }
    int st = 0, sum = 0, count = 0;
    for (int end = 0; end < nums.size(); end++) {
        sum =sum+ nums[end];
        while (sum > goal) {
            sum =sum- nums[st];
            st++;
        }

        count =count+(end - st + 1);
    }
    return count;
}

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums,goal)-atMost(nums,goal-1);
    }
};