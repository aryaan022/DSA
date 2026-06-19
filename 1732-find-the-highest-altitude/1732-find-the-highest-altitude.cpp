class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res=0;
        int curr=0;
        for (int g:gain) {
            curr=curr+g;
            res=max(res,curr);
        }
        return res;
    }
};