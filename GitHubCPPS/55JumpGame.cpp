class Solution {
public:
    bool canJump(vector<int>& nums) {
        int s_r = 0; int e_r = 0;
        for (int pos = 0; pos < nums.size(); pos++) {
            int steps = nums[pos];
            if (steps == 0) continue;
            if (pos > e_r) return false;
            if (e_r < pos + steps) e_r = pos + steps;
        }
        if (e_r < nums.size() - 1) return false;
        return true;
    }
};