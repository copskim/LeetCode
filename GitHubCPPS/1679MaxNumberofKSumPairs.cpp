class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int li = 0, ri = nums.size() - 1;
        int hitn = 0;
        while (li < ri) {
            int sum = nums[li] + nums[ri];
            if (sum == k) {
                hitn++;
                li++;
                ri--;
            }
            else if (sum < k) {
                li++;
            }
            else {
                ri--;
            }
        }
        return hitn;
    }
};