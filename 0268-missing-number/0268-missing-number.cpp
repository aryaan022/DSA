class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int actualsum=0;
        int currsum=0;
        int misn=0;
        for(int i=0;i<=nums.size();i++){
            actualsum +=i;
        }
        for(int i=0;i<nums.size();i++){
            currsum +=nums[i];
        }
        misn= actualsum-currsum;
        return misn;
    }
};