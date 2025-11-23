class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int sum =0;
        int opt1=INT_MAX;
        int opt2=INT_MAX;
        int n= nums.size();
        for(int i =0; i<n;i++){
            sum =nums[i]+sum;
        }
        if(sum%3==0){
            return sum;
        }
        int r=sum%3;
        int small1 = INT_MAX, small2 = INT_MAX;
        int small3 = INT_MAX, small4 = INT_MAX;
        
        for(int i =0; i<n;i++){
            int rem =nums[i]%3;
            if(rem==r){
                opt1=min(opt1,nums[i]);
            }

            //second
            if(r==1 && rem==2){
                if(nums[i]<small1){
                    small2=small1;
                    small1=nums[i];
                }else if(nums[i]<small2){
                    small2=nums[i];
                }
            }
            if(r==2 &&rem==1){
                if(nums[i] < small3){
                small4 = small3;
                small3 = nums[i];
                } else if(nums[i] < small4){
                small4 = nums[i];
                }
            }

        }
        if(r == 1 && small1 != INT_MAX && small2 != INT_MAX){
            opt2 = small1 + small2;
        }

        if(r == 2 && small3 != INT_MAX && small4 != INT_MAX){
            opt2 = small3 + small4;
        }
        int rv = min(opt1,opt2);
        return sum-rv;
    }
};