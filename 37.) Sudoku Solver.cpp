class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board) {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j] == '.')
                {
                    for(char digit='1'; digit<='9'; digit++)
                    {
                        if(isValid(board, i, j, digit))
                        {
                            board[i][j] = digit;

                            if(solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>>& board, int row, int col, char digit) {
        for(int i=0; i<9; i++)
        {
            if(board[i][col] == digit)
                return false;
            if(board[row][i] == digit)
                return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == digit)
                return false;
        }
        return true;
    }
};