class Solution {
public:
    int thirdMax(vector<int>& nums) {

        long long l = LLONG_MIN;
        long long se = LLONG_MIN;
        long long th = LLONG_MIN;

        for(int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            if(x == l || x == se || x == th) continue;   

            if(x > l) {
                th = se;
                se = l;
                l = x;
            }
            else if(x > se) {
                th = se;
                se = x;
            }
            else if(x > th) {
                th = x;
            }
        }

        if(th == LLONG_MIN) return l;

        return th;
    }
};
