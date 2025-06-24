class Solution {
public:
    const int thresh = 1e9 + 7;
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        vector<vector<int>> cntmat(m, vector<int>(n, 0));
        long long tpaths = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                long long npaths;
                if (cntmat[i][j]) npaths = cntmat[i][j];
                else {
                    npaths = traverse(grid, i, j, cntmat);
                    cntmat[i][j] = npaths;
                }
                tpaths += npaths % thresh;
                tpaths %= thresh;
            }
        }
        return tpaths;
    }
private:
    long long traverse(vector<vector<int>>& g, int row, int col, vector<vector<int>>& cm) {
        int m = g.size(); int n = g[0].size();
        long long count = 0;
        count++;
        long long cnt;
        int cv = g[row][col];
        if (row > 0) {
            if (g[row - 1][col] > cv) {
                if (cm[row - 1][col]) cnt = cm[row - 1][col];
                else {
                    cnt = traverse(g, row - 1, col, cm);
                    cm[row - 1][col] = cnt;
                }
                cnt %= thresh;
                count += cnt;
            }
        }
        if (row < m - 1) {
            if (g[row + 1][col] > cv) {
                if (cm[row + 1][col]) cnt = cm[row + 1][col];
                else {
                    cnt = traverse(g, row + 1, col, cm);
                    cm[row + 1][col] = cnt;
                }
                cnt %= thresh;
                count += cnt;
            }
        }
        if (col > 0) {
            if (g[row][col - 1] > cv) {
                if (cm[row][col - 1]) cnt = cm[row][col - 1];
                else {
                    cnt = traverse(g, row, col - 1, cm);
                    cm[row][col - 1] = cnt;
                }
                cnt %= thresh;
                count += cnt;
            }
        }
        if (col < n - 1) {
            if (g[row][col + 1] > cv) {
                if (cm[row][col + 1]) cnt = cm[row][col + 1];
                else {
                    cnt = traverse(g, row, col + 1, cm);
                    cm[row][col + 1] = cnt;
                }
                cnt %= thresh;
                count += cnt;
            }
        }
        count %= thresh;
        return count;
    }
};