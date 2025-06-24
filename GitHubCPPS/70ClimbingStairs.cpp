class Solution {
private:
    vector<int>cache;
public:
    int climbStairs(int n) {
        cache.resize(45 + 1, 0);
        cache[0] = 0;
        cache[1] = 1;
        cache[2] = 2;
        return dp(n);
    }
private:
    int dp(int n) {
        if (cache[n]) return cache[n];
        if (!cache[n - 1]) cache[n - 1] = dp(n - 1);
        if (!cache[n - 2]) cache[n - 2] = dp(n - 2);
        return cache[n - 1] + cache[n - 2];
    }
};