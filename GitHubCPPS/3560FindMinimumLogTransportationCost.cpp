class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if (n <= k && m <= k) return 0;
        else if (m > k && n > k) return -1;
        else {
            return (long long)k * max(m - k, n - k);
        }
    }
};