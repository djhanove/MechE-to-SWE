class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        if(n == 0)
            return vector<vector<string>>();

        vector<string> board(n, string(n,'.')); //create board and init each entry with "."
        
        vector<vector<string>> solution;
        recursiveSolve(solution, board, 0);
        return solution;
        
        
    }
    
    bool isSafe(const vector<string> &board, const int &row, const int &col) {
        /* Function to check whether or not a move is valid */
        
        int i;
        int j;
        for(i = 0; i < col; i++)
            if(board[row][i] == 'Q')
                return false;
        
        for(i = row,j = col; i >= 0 && j >= 0; i--, j--)
            if(board[i][j] == 'Q')
                return false;
        
        for(i = row, j = col; j >= 0 && i < board.size(); i++, j--)
            if(board[i][j] == 'Q')
                return false;
        return true;
    }
    
    void recursiveSolve(vector<vector<string>> &solution, vector<string> &board, const int &col) {
        if(col >= board.size()) {
            solution.push_back(board);
            return;
        }
        for(size_t i = 0; i < board.size(); i++) {
            if(isSafe(board, i, col)) {
                board[i][col] = 'Q';
                recursiveSolve(solution, board, col +1);
                board[i][col] = '.';
            }
        }
    }
};
