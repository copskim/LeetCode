class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        for (vector<int>& iv : grid) {
            sort(iv.begin(), iv.end(), [](const int& a, const int& b) {return a > b; });
        }
        vector<int> g;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < limits[i]; j++) {
                g.push_back(grid[i][j]);
            }
        }
        sort(g.begin(), g.end(), [](const int& a, const int& b) {return a > b; });
        long long lsum = 0;
        for (int i = 0; i < k; i++) {
            lsum += g[i];
        }
        return lsum;
    }
};