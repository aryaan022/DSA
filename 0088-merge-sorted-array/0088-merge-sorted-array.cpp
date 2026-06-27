class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1 = m-1;
        int n2 = n-1;
        int ts =m+n-1;

        while(n1>=0&&n2>=0){
            if(nums1[n1]>nums2[n2]){
                nums1[ts]=nums1[n1];
                n1--;
                ts--;
            }
            else{
                nums1[ts]=nums2[n2];
                n2--;
                ts--;
            }
        }
        while(n2>=0){
            nums1[ts]=nums2[n2];
            n2--;
            ts--;
        }
    }
};