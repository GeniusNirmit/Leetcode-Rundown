class Solution {
public:
    int totalNQueens(int n) {
        int counter = 0;
        vector<string> board(n, string(n, '.'));
        vector<bool> left(n, false), lowerDiagonal(2*n-1, false), upperDiagonal(2*n - 1, false);

        placeQueens(n, 0, counter, board, left, lowerDiagonal, upperDiagonal);

        return counter;
    }
    void placeQueens(int n, int col, int& counter, vector<string>& board, vector<bool>& left, vector<bool>& lowerDiagonal, vector<bool>& upperDiagonal) {
        if(col == n)
        {
            counter++;
            return;
        }

        for(int i=0; i<n; i++)
        {
            if(!left[i] && !lowerDiagonal[col + i] && !upperDiagonal[n - 1 + col - i])
            {
                board[i][col] = 'Q';
                left[i] = true;
                lowerDiagonal[col + i] = true;
                upperDiagonal[n - 1 + col - i] = true;

                placeQueens(n, col + 1, counter, board, left, lowerDiagonal, upperDiagonal);

                board[i][col] = '.';
                left[i] = false;
                lowerDiagonal[col + i] = false;
                upperDiagonal[n - 1 + col - i] = false;
            }
        }
    }
};