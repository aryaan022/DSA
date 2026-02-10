class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n =nums.size();
        int m = multiplier;
        
        while(k!=0){
            int min =INT_MAX;
            int c=0;
            int indx=0;
            for(int i=0;i<n;i++){
                if(nums[i]<min){
                    indx= i;
                    min =nums[i];
                }
            }
            if(nums[indx]==min){
                nums[indx]=min*m;
            }

            k--;
        }
        return nums;   
    }
};