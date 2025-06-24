class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for (int iv : nums) sum += iv;
        int ops = sum % k;
        return ops;
    }
};