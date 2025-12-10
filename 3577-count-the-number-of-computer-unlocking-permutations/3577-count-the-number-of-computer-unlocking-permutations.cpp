class Solution {
public:
    static const long long MOD = 1000000007;

    long long fact(long long n){
        long long r = 1;
        for(long long i = 1; i <= n; i++) r = r * i % MOD;
        return r;
    }

    int countPermutations(vector<int>& c) {
        int n = c.size();
        int root = c[0];

        for(int i = 1; i < n; i++)
            if(c[i] <= root) return 0;

        return fact(n - 1);
    }
};
