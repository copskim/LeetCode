class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = size(matrix);
        int sq = n / 2;
        for (int k = 0; k < sq; k++) {
            for (int i = k; i < n - k - 1; i++) {
                int t0 = matrix[k][i];
                int t1 = matrix[i][n - k - 1];
                int t2 = matrix[n - k - 1][n - 1 - i];
                int t3 = matrix[n - 1 - i][k];
                matrix[k][i] = t3;
                matrix[i][n - k - 1] = t0;
                matrix[n - k - 1][n - 1 - i] = t1;
                matrix[n - 1 - i][k] = t2;
            }
        }
    }
};