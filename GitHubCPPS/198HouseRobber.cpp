class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        int pprev = nums[0];
        int prev = nums[1];
        for (int i = 2; i < n; i++) {
            int cur = max(prev, pprev + nums[i]);
            int tmp = prev;
            prev = cur;
            pprev = max(tmp, pprev);
        }
        return prev;
    }
};