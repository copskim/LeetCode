class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(usageLimits.begin(), usageLimits.end());
        int maxGroups = 0;
        long long amount = 0;
        for (int lim : usageLimits) {
            amount += lim;
            if (amount > maxGroups) {
                maxGroups++;
                amount -= maxGroups;
            }
        }
        return maxGroups;
    }
};