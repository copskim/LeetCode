class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.size(); int l2 = text2.size();
        vector<vector<int>> m(l1 + 1, vector<int>(l2 + 1));
        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (text1[i - 1] == text2[j - 1]) m[i][j] = m[i - 1][j - 1] + 1;
                else m[i][j] = max(m[i - 1][j], m[i][j - 1]);
            }
        }
        return(m[l1][l2]);
    }
};