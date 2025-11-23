class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int w=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[w]=nums[i];
                w++;
            }
        }

        while(w<n){
            nums[w]=0;
            w++;
        }
        for(int i=0;i<n;i++){
            cout<<nums[i]<<",";
        }
    }
};