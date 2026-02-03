class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>>q;
        for(int i=0;i<tickets.size();i++){
            q.push({i,tickets[i]});
        }
        int t=0;
        while(!q.empty()){
            pair<int,int>curr=q.front();
            q.pop();
            t++;
            curr.second --;
            if(curr.first==k && curr.second==0){
                return t;
            }
            if(curr.second>0){
                q.push(curr);
            }
        }
        return t;
    }
};