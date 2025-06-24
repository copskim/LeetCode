class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        if (nums.size() == 2) return 2;

        int maxN = nums.size();
        int exp2 = 0;
        for (int v = maxN; v >= 1; v /= 2) { exp2++; }
        int res = 1;
        while (exp2-- > 0) res *= 2;
        return res;
    }
};