class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> isIt(9, false);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue;
                c -= '1';
                if (isIt[c]) return false;
                isIt[c] = true;
            }
            fill(isIt.begin(), isIt.end(), false);
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[j][i];
                if (c == '.') continue;
                c -= '1';
                if (isIt[c]) return false;
                isIt[c] = true;
            }
            fill(isIt.begin(), isIt.end(), false);
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = i * 3; k < i * 3 + 3; k++) {
                    for (int l = j * 3; l < j * 3 + 3; l++) {
                        char c = board[k][l];
                        if (c == '.') continue;
                        c -= '1';
                        if (isIt[c]) return false;
                        isIt[c] = true;
                    }
                }
                fill(isIt.begin(), isIt.end(), false);
            }
        }
        return true;
    }
};