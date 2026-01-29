class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int st=0;
        int ed=0;
        int currsum=0;
        int n=nums.size();
        int minlen = INT_MAX;

        while(ed<n){
            currsum=currsum+nums[ed];
            if(currsum==target){
                int len =ed-st+1;
                minlen=min(minlen,len);
            }
            else if(currsum>target){
                while(currsum>=target){
                    if(st<=ed){
                        int len = ed-st+1;
                        minlen=min(minlen,len);
                        currsum =  currsum -nums[st];
                        st++;
                    }
                    else{
                        break;
                    }
                }
            }
            ed++;
            
        }
        if(minlen==INT_MAX){
            return 0;
        }
        return minlen;
        
    }
};