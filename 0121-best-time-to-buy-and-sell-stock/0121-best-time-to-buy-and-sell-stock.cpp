class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowp=INT_MAX;
        int maxp=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<lowp){
                lowp=prices[i];
            }
            else{
                if(prices[i]-lowp>maxp){
                    maxp= prices[i]-lowp;
                }
            }
        }
        return maxp;
    }
};