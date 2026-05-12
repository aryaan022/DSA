class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        unordered_map<int,int>freq;
        for(int card:hand){
            freq[card]++;
        }
        priority_queue<int, vector<int>, greater<int>> pq; //min heap

        for(auto it:freq){//pusing cards into min heap
            pq.push(it.first);
        }


        while(!pq.empty()){
            while(!pq.empty() && freq[pq.top()] == 0) {
                pq.pop();
            }
            if(pq.empty()) {
                break;
            }
            int start = pq.top();

            for(int i=0;i<groupSize;i++){
                int curr = start+i;

                if(freq[curr] == 0) {
                    return false;
                }
                freq[curr]--;
            }

        }
        return true;
        
    }
};