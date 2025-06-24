class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int mincs = 0, mincsp = 0, mincspp = 0;
        for (int i = 2; i <= cost.size(); i++) {
            mincs = min(mincspp + cost[i - 2], mincsp + cost[i - 1]);
            mincspp = mincsp;
            mincsp = mincs;
        }
        return mincs;
    }
};