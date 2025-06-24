class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        long long largest = -1;
        long long partial = 0;
        for (int i = n - 2; i >= 0;) {
            if (nums[i + 1] >= nums[i]) {
                partial += nums[i + 1] + nums[i];
                i--;
                while (i >= 0 && partial >= nums[i]) {
                    partial += nums[i];
                    i--;
                }
                if (i >= 0 && nums[i] > partial) partial = nums[i];
            }
            else partial = nums[i];
            if (partial > largest) largest = partial;
            partial = 0;
            i--;
        }
        return largest;
    }
};