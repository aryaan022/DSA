class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> freq;

        for(char task:tasks){
            freq[task]++;
        }
        

        priority_queue<int> pq; //max heap use krre hai to pick the highest frequencly left character

        //pushing the freq into max heap
        for(auto it : freq){
            pq.push(it.second);
        }

        int time=0;
        
        while(!pq.empty()){
            vector<int>temp;
            int cycle = n + 1;
            int i =0;

            while(!pq.empty()&&i<cycle){
                int mostfrequency = pq.top();
                pq.pop();

                mostfrequency--;
                if(mostfrequency>0){
                    temp.push_back(mostfrequency);
                }
                time++;
                i++;

            }
            for(int val:temp){
                pq.push(val);
            }
            if(pq.empty()){
                break;
            }
            time =time+(cycle-i);
        }
        
        return time;
    }
};