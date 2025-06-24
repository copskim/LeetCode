class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> paths(n, 1);
        for (int r = 1; r < m; r++) {
            for (int c = 1; c < n; c++) {
                paths[c] += paths[c - 1];
            }
        }
        return paths[n - 1];
    }
};