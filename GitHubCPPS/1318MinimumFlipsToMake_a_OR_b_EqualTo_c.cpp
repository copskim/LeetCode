
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int mf = 0;
        for (int i = 0; i < 31; i++) {
            int mask = 0x00000001 << i;
            int a_bit = a & mask;
            int b_bit = b & mask;
            int c_bit = c & mask;
            if (c_bit != 0) {
                if (a_bit == 0 && b_bit == 0) mf++;
            }
            else {
                if (a_bit != 0) mf++;
                if (b_bit != 0) mf++;
            }
        }
        return mf;
    }
};