
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ents = nums.size();
        int maxOnes = 0;
        int cntZeroes;
        int li, ri;

        cntZeroes = 0;
        for (li = 0, ri = 0; ri < ents; ) {
            if (cntZeroes <= k) {
                if (nums[ri] == 0) cntZeroes++;
                if (cntZeroes <= k) { if (ri - li + 1 > maxOnes) maxOnes = ri - li + 1; }

                ri++;
            }
            else {
                while (cntZeroes > k && li < ri) {
                    if (nums[li] == 0) cntZeroes--;
                    li++;
                }
            }
        }
        return(maxOnes);
    }
};