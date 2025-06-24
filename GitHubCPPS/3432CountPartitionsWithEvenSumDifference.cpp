class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int oddcnt = 0;
        for (int i : nums) if ((i % 2)) oddcnt++;
        if (oddcnt % 2) return 0;
        return nums.size() - 1;
    }
};