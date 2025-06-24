class Solution {
public:
    int mySqrt(int x) {
        const int xmax = 46341;
        int lb = 0;
        int rb = xmax;
        while ((rb - lb) > 1) {
            int mid = (lb + rb) / 2;
            if (x > mid * mid) lb = mid;
            else if (x < mid * mid) rb = mid;
            else return mid;
        }
        return lb;
    }
};