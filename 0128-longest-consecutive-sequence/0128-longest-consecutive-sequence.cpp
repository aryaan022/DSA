class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int maxleng=0;
        for(auto n :s){
            int length=1;
            if(s.find(n-1)==s.end()){
                int curr=n;
                while(s.find(curr+1)!=s.end()){
                    curr++;
                    length++;
                }
                maxleng=max(length,maxleng);
            }
        }
        return maxleng;
    }
};