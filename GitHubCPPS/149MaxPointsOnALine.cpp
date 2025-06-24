class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int maxpts = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<long long, int> pht;
            int lmaxpts = 0;
            int stpcc = 1;
            int vpts = 0;
            for (int j = i + 1; j < n; j++) {
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                if (dx == 0 && dy == 0) stpcc++;
                else if (dx == 0) vpts++;
                else {
                    int g = gcd(dy, dx);
                    if (g) { dx /= g; dy /= g; };
                    if (dx < 0 && dy <= 0) dx = -dx, dy = -dy;
                    else if (dx < 0 && dy >= 0) dx = -dx, dy = -dy;
                    long long slope = ((long long)dx << 32) | (dy & 0xffffffff);
                    ++pht[slope];
                    lmaxpts = max(lmaxpts, pht[slope]);
                }
                lmaxpts = max(lmaxpts, vpts);
            }
            maxpts = max(maxpts, lmaxpts + 1);
        }
        return maxpts;
    }
};