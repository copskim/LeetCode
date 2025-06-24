class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rsum = 0, lsum = 0;
        int ents = nums.size();
        for (int i = 0; i < ents; i++) {
            rsum += nums[i];
        }
        for (int pivot = 0; pivot < ents; pivot++) {
            rsum -= nums[pivot];
            if (rsum == lsum) return pivot;
            lsum += nums[pivot];
        }
        return -1;
    }
};