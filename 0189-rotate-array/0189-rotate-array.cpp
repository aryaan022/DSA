class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // important

        // STEP 1: reverse the whole array
        int s = 0, e = n - 1;
        while(s < e){
            swap(nums[s], nums[e]);
            s++;
            e--;
        }

        // STEP 2: reverse first k elements
        s = 0;
        e = k - 1;
        while(s < e){
            swap(nums[s], nums[e]);
            s++;
            e--;
        }

        // STEP 3: reverse last n-k elements
        s = k;
        e = n - 1;
        while(s < e){
            swap(nums[s], nums[e]);
            s++;
            e--;
        }
    }
};
