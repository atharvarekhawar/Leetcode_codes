class Solution {
public:
    bool isSafe(vector<string> board, int row, int col, int n) {
        int x = row - 1;
        int y = col;

        while (x >= 0) {
            if (board[x--][y] == 'Q') {
                return false;
            }
        }

        x = row - 1;
        y = col - 1;

        while (x >= 0 && y >= 0) {
            if (board[x--][y--] == 'Q') {
                return false;
            }
        }

        x = row - 1;
        y = col + 1;

        while (x >= 0 && y < n) {
            if (board[x--][y++] == 'Q') {
                return false;
            }
        }

        return true;
    }
    void solve(vector<vector<string>>& res, vector<string>& board, int n,int row) {
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int i = 0; i < n; ++i) {
            board[row][i] = 'Q';
            bool safe = isSafe(board, row, i, n);
            if (safe) {
                solve(res, board, n, row + 1);
            }
            board[row][i] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board;
        for (int i = 0; i < n; ++i) {
            string s = "";
            for (int j = 0; j < n; j++) {
                s += '.';
            }
            board.push_back(s);
        }
        solve(res, board, n, 0);
        return res;
    }
};