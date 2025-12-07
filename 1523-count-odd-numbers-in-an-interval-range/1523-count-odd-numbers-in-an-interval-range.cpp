class Solution {
public:
    int countOdds(int low, int high) {
        int total = high - low + 1;
        int extra = 0;
        if (low % 2 == 1 && high % 2 == 1) {
            extra = 1;
        }
        return (total / 2) + extra;
    }
};
