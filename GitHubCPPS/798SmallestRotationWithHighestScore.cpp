class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> positiveSubA(2 * n, 0);
        int maxpoints = 0;
        for (int i = 0; i < n; i++) {
            int sub = i - nums[i];
            if (sub >= 0) {
                positiveSubA[sub]++;
                maxpoints++;
            }
        }
        int k = 0;
        int cntNonNeg = maxpoints;
        for (int i = 1; i < n; i++) {
            cntNonNeg -= positiveSubA[i - 1];
            int newsub = n - 1 - nums[i - 1] + i; //append to the tail
            if (newsub >= 0) {
                cntNonNeg++;
                positiveSubA[newsub]++;
            }
            if (cntNonNeg > maxpoints) {
                maxpoints = cntNonNeg, k = i;
            }
        }
        return k;
    }
};