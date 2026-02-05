class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tg=0;
        int tc=0;
        int pos=0;
        int tank=0;
        for(int i=0;i<gas.size();i++){
            tg=tg+gas[i];
            tc=tc+cost[i];

        }
        if(tg<tc){
            return -1;
        }
        for(int i=0;i<gas.size();i++){
            tank=tank+gas[i]-cost[i];
            if(tank<0){
                pos=i+1;
                tank=0;
            }
        }
        return pos;
        
    }
};