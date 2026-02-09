class Solution {
public:
    string getSmallestString(int n, int k) {
        k =k- n;
        string res(n , 'a');
        for(int i = n - 1; i >= 0&&k; --i){
            int add = min(k , 25);
            res[i] =res[i]+ add;
            k =k- add;
        }
        return res;
    }
};