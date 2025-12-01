#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for (int b : batteries) {
            sum += b;
        }

        long long left = 1; 
        long long right = sum / n; 
        long long ans = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            
            if (canRun(n, batteries, mid)) {
                ans = mid;      
                left = mid + 1;
            } else {
                right = mid - 1; 
            }
        }
        
        return ans;
    }

private:
    bool canRun(int n, vector<int>& batteries, long long targetTime) {
        long long currentPower = 0;
        long long requiredPower = targetTime * n;
        
        for (int b : batteries) {
          
            currentPower += min((long long)b, targetTime);
        }
        
        return currentPower >= requiredPower;
    }
};