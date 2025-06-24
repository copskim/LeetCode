class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int n = board.size();
        int rowRook{}, colRook{};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'R') {
                    rowRook = i, colRook = j;
                    break;
                }
            }
        }
        int pawns = 0;
        for (int i = colRook; i < n; i++) {
            if (board[rowRook][i] == 'B') break;
            if (board[rowRook][i] == 'p') {
                pawns++;
                break;
            }
        }
        for (int i = colRook; i >= 0; i--) {
            if (board[rowRook][i] == 'B') break;
            if (board[rowRook][i] == 'p') {
                pawns++;
                break;
            }
        }
        for (int i = rowRook; i < n; i++) {
            if (board[i][colRook] == 'B') break;
            if (board[i][colRook] == 'p') {
                pawns++;
                break;
            }
        }
        for (int i = rowRook; i >= 0; i--) {
            if (board[i][colRook] == 'B') break;
            if (board[i][colRook] == 'p') {
                pawns++;
                break;
            }
        }
        return pawns;
    }
};