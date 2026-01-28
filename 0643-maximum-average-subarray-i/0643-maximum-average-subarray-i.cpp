class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg=0;
        double avg1=0;
        int n = nums.size();
        double ma=0;
        int ws=0;
        for(int i=0;i<k;i++){
            ws=ws+nums[i];
        }
            avg1=(double)ws/k;
            ma= avg1;
        for(int i=k;i<n;i++){
            ws=ws+nums[i]-nums[i-k];
            avg =(double) ws/k;
            ma = max(ma,avg);
        }
        return ma;
    }
};