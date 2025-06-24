class Solution {
public:
    int addDigits(int num) {
        int dgtSum = 0;
        int iv = num;
        while (1) {
            while (iv > 0) {
                dgtSum += iv % 10;
                iv /= 10;
            }
            if (dgtSum < 10) break;
            iv = dgtSum;
            dgtSum = 0;
        }
        return dgtSum;

    }
};