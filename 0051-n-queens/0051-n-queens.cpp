class Solution {
public:
    vector<vector<string>> result;

    bool isSafe(vector<string>& board, int row, int col, int n) {

        //horiontal
        for(int j=0;j<n;j++){
            if(board[row][j]=='Q'){
                return false;
            }
        }
        //vertical
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        //left diagonal 
        for(int i=row,j=col; i>=0&&j>=0; i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        //right diagnol
        for(int i=row,j=col; i>=0&&j<n; i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }

    void solve(int row, vector<string>& board, int n) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(row + 1, board, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(0, board, n);
        return result;
    }
};
