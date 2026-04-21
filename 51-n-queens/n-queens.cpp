class Solution {
private:
    vector<int> cols, diag1, diag2;

    void generate(vector<vector<string>> &ans, vector<string> &board, int n, int row){
        // Base case: all queens placed
        if(row == n){
            ans.emplace_back(board);
            return;
        }

        // Try placing queen in each column of current row
        for(int col = 0; col < n; col++){

            // Check if position is safe
            if(cols[col] || diag1[row + col] || diag2[row - col + (n - 1)])
                continue;

            // Place queen
            cols[col] = 1;
            diag1[row + col] = 1;
            diag2[row - col + (n - 1)] = 1;
            board[row][col] = 'Q';

            // Recur for next row
            generate(ans, board, n, row + 1);

            // Backtrack: remove queen
            cols[col] = 0;
            diag1[row + col] = 0;
            diag2[row - col + (n - 1)] = 0;
            board[row][col] = '.';
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {

        // Initialize tracking arrays
        cols.assign(n, 0);
        diag1.assign(2*n - 1, 0);
        diag2.assign(2*n - 1, 0);

        vector<vector<string>> ans;

        // Initialize empty board
        vector<string> board(n, string(n, '.'));

        // Start backtracking from row 0
        generate(ans, board, n, 0);

        return ans;
    }
};