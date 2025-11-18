class Solution {
public:
    int reverse(int x) {
        int temp =x;
        long int rev=0;
        while(temp !=0){
            int d =temp%10;
            rev=10*rev+d;
            if(rev>INT_MAX)return 0;
            if(rev<INT_MIN)return 0;
            temp =temp/10;
        }
        return rev;
    }
};