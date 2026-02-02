class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n= nums.size();
        vector<int>left(n);
        vector<int>right(n);
        vector<int>ans(n);
        int ls=0;
        int rs=0;
        for(int i =0;i<n;i++){
            left[i]=ls;
            ls=ls+nums[i];
        }
        for(int i=n-1;i>=0;i--){
            right[i]=rs;
            rs= rs+nums[i];
        }
        for(int i=0;i<n;i++){
            ans[i]= abs(left[i]-right[i]);
        }
        return ans;
    }
};