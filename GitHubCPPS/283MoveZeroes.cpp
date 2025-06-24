class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ents = nums.size();
        int zeros = 0;
        for (int i = 0; i < ents; i++) {
            if (nums[i] == 0) {
                zeros++; continue;
            }
            if (zeros) nums[i - zeros] = nums[i];
        }
        for (int i = 0; i < zeros; i++) {
            nums[ents - i - 1] = 0;
        }

    }
};