class Solution {
public:
    void dfs(int row, int col, int m, int n, vector<vector<char>>& board,
             vector<vector<bool>>& visited) {
        visited[row][col] = true;

        if (row - 1 >= 0 && board[row - 1][col] == 'O' &&
            visited[row - 1][col] == false) {
            dfs(row - 1, col, m, n, board, visited);
        }
        if (row + 1 < m && board[row + 1][col] == 'O' &&
            visited[row + 1][col] == false) {
            dfs(row + 1, col, m, n, board, visited);
        }
        if (col - 1 >= 0 && board[row][col - 1] == 'O' &&
            visited[row][col - 1] == false) {
            dfs(row, col - 1, m, n, board, visited);
        }
        if (col + 1 < n && board[row][col + 1] == 'O' &&
            visited[row][col + 1] == false) {
            dfs(row, col + 1, m, n, board, visited);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O' && visited[i][0] == false) {
                dfs(i, 0, m, n, board, visited);
            }
            if (board[i][n - 1] == 'O' && visited[i][n - 1] == false) {
                dfs(i, n - 1, m, n, board, visited);
            }
        }

        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O' && visited[0][j] == false) {
                dfs(0, j, m, n, board, visited);
            }
            if (board[m - 1][j] == 'O' && visited[m - 1][j] == false) {
                dfs(m - 1, j, m, n, board, visited);
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};