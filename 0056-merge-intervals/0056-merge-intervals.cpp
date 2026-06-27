class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end()); //sort on the basis of start time
        vector<int>curr=intervals[0];
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]<=curr[1]){
                //merge intervals
                curr[1]=max(curr[1],intervals[i][1]);
            }else{
                ans.push_back(curr);
                curr=intervals[i];
            }
        }
        ans.push_back(curr);
        return ans;
    }
};