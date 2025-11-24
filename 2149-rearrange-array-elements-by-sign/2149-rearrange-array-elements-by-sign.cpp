class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n =nums.size();
        vector<int> pos(n/2);
        vector<int> neg(n/2);
        vector<int> res(n);
        int p=0,q=0;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                neg[p]=nums[i];
                p++;
            }
            else{
                pos[q]=nums[i];
                q++;
            }
        }
        int x=0,y=0;
        for(int i =0;i<n;i++){
            if(i%2==0){
                res[i]=pos[x];
                x++;
            }
            else{
                res[i]=neg[y];
                y++;
            }
        }
        return res;
    }
};