class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sumMax = INT_MIN;
        int ents = nums.size();

        int psum = 0.0;
        for (int i = 0; i < k; i++) { psum += nums[i]; }

        for (int i = 0; ; i++) {
            if (psum > sumMax) sumMax = psum;
            if (i == ents - k)break;
            psum -= nums[i]; psum += nums[i + k];
        }
        std::cout << sumMax << std::endl;
        return (double)sumMax / k;

    }
};