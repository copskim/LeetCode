class Solution {
private:
    unordered_map<int, double> memoiz;
public:
    double myPow(double x, int n) {
        if (x == 0.0) return 0.0;
        if (n == 0) return 1.0;
        double r;
        memoiz.clear();
        if (n < 0) {
            if (n == INT_MIN) {
                r = recPow(x, -(n + 1));
                r *= x;
            }
            else r = recPow(x, -n);
            return 1.0 / r;
        }
        return recPow(x, n);
    }
private:
    double recPow(double x, int n) {
        if (memoiz.count(n)) return memoiz[n];
        if (n == 1) return x;
        double r1 = recPow(x, n / 2);
        double r2 = recPow(x, n / 2 + (n & 1));
        double r = r1 * r2;
        memoiz[n] = r;
        return r;
    }
};