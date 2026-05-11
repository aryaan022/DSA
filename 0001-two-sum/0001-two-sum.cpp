class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n =nums.size();
        unordered_map<int,int>m; //key arr[i] //val= i
        for(int i=0;i<n;i++){
            int  comp =target-nums[i];
            if(m.count(comp)){
                return{m[comp],i};
                break;
            }
            m[nums[i]]=i; // m[key]=val
        }
        return{};
    }
};