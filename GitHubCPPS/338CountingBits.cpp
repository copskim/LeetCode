class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> r;
        r.push_back(0);
        if (n >= 1) r.push_back(1);
        if (n < 2) return r;
        int pw2_l = 2; int pw2_r = 4;
        for (int i = 2; i <= n; i++) {
            if (i < pw2_r) {
                r.push_back(r[i - pw2_l] + 1);
                continue;
            }
            r.push_back(1);
            pw2_r *= 2; pw2_l *= 2;
        }
        return r;
    }
};