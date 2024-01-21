class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (search(m, n, i, j, board, word, 0))
                    return true;
            }
        }
        return false;
    }
    bool search(int &m, int &n, int row, int col, vector<vector<char>> &board, string &word, int ind)
    {
        if (ind == word.length())
            return true;
        if (row < 0 || row >= m || col < 0 || col >= n)
            return false;
        if (board[row][col] != word[ind])
            return false;

        char tempLetter = board[row][col];
        board[row][col] = '*';
        bool up = search(m, n, row - 1, col, board, word, ind + 1);
        bool down = search(m, n, row + 1, col, board, word, ind + 1);
        bool left = search(m, n, row, col - 1, board, word, ind + 1);
        bool right = search(m, n, row, col + 1, board, word, ind + 1);
        board[row][col] = tempLetter;

        if (up || down || left || right)
            return true;
        return false;
    }
};