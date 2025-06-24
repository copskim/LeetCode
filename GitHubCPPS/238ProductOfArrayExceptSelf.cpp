class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result(n, 1);

        //prefix calculation
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            result[i] = prefix;
            prefix *= nums[i];
        }
        //suffix calculation
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= suffix;
            suffix *= nums[i];
        }
        return result;
    }
};