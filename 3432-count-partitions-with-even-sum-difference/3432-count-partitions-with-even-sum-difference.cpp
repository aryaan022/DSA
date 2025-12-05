class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total=0;
        int lsum=0;
        int rsum=0;
        int n=nums.size();
        int c=0;
        for(int i=0;i<n;i++){
            total = total+nums[i];
        }

        for(int i=0;i<n-1;i++){
            lsum=lsum+nums[i];
            rsum=total-lsum;
            if((lsum%2)==(rsum%2)){
                c++;
            }
        }
        return c;
        
    }
};