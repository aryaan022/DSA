class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int maxl=0;
        for(auto it :st){
            if(st.find(it-1)==st.end()){
                int curr=it;
                int length =1;
                while(st.find(curr+1)!=st.end()){
                    curr++;
                    length++;
                }
                maxl=max(maxl,length);
            }
        }
        return maxl;
    }
};