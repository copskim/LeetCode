class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ents = nums.size();
        int zeroCnt = 0;
        int maxCnt = 0;
        int li = 0;

        for (int ri = 0; ri < ents; ri++) {
            if (nums[ri] == 0) {
                zeroCnt++;
            }
            while (zeroCnt > 1) {
                if (nums[li] == 0) {
                    zeroCnt--;
                }
                li++;
            }
            if (ri - li > maxCnt) maxCnt = ri - li;
        }
        return maxCnt;

    }
};