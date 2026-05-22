class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>PQ;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            PQ.push(nums[i]);
        }
        while(!PQ.empty()){
            ans.push_back(PQ.top());
            PQ.pop();
        }
        return ans;
    }
};