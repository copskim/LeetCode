class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<bool> tfa(n + 1, false);
        bool toggle = true;
        for (int i = 0; i < n; i++) {
            int togcnt = 0;
            for (int j = 0; j < n; j++) {
                if (tfa[matrix[i][j]] == toggle) return false;
                tfa[matrix[i][j]] = toggle;
                togcnt++;
            }
            if (togcnt != n) return false;
            toggle = toggle ? false : true;
        }
        for (int i = 0; i < n; i++) {
            int togcnt = 0;
            for (int j = 0; j < n; j++) {
                if (tfa[matrix[j][i]] == toggle) return false;
                tfa[matrix[j][i]] = toggle;
                togcnt++;
            }
            if (togcnt != n) return false;
            toggle = toggle ? false : true;
        }
        return true;
    }
};