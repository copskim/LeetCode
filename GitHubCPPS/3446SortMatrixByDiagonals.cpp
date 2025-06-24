class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>diag;
        for (int diff = -n + 1; diff <= n - 1; diff++) {
            for (int i = 0; i < n; i++) {
                int j = i - diff;
                if (j >= 0 && j < n) {
                    diag.push_back(grid[i][j]);
                }
            }
            if (diag.size() > 1) {
                if (diff >= 0)
                    sort(diag.begin(), diag.end(), [](const int& a, const int& b) {return a > b; });
                else
                    sort(diag.begin(), diag.end());
            }
            int k = 0;
            for (int i = 0; i < n; i++) {
                int j = i - diff;
                if (j >= 0 && j < n) {
                    grid[i][j] = diag[k];
                    k++;
                }
            }
            diag.resize(0);
        }
        return grid;
    }
};