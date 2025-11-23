class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int count1=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                count++;
                if(count1<count){
                    count1= count;
                }
            }
            else if(nums[i]==0){
                if(count1<count){
                    count1= count;
                }
                count=0;
            }
        }
        return count1;
    }
};