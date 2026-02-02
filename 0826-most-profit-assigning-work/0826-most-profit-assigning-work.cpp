class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> jobs;
        for(int i = 0; i < difficulty.size(); i++){
            jobs.push_back({difficulty[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());  
        sort(worker.begin(), worker.end());
        int ans = 0;
        int maxProfit = 0;
        int j = 0;
        for(int w : worker){
            while(j < jobs.size() && jobs[j].first <= w){
                maxProfit = max(maxProfit, jobs[j].second);
                j++;
            }
            ans =ans+ maxProfit;
        }
        return ans;
    }
};
