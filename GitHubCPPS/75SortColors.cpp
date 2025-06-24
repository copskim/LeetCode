class Solution {
public:
    void sortColors(vector<int>& nums) {
        int redcc = 0, whitecc = 0, bluecc = 0;
        for (int c : nums) {
            if (c == 0) redcc++;
            else if (c == 1) whitecc++;
            else if (c == 2) bluecc++;
        }
        int i = 0;
        while (redcc-- > 0) nums[i++] = 0;
        while (whitecc-- > 0) nums[i++] = 1;
        while (bluecc-- > 0) nums[i++] = 2;
    }
};