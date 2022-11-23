class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<9;i++)
        {
            unordered_map<char, int> hash;
            for(int j=0;j<9;j++)
            {
                if(board[i][j] != '.')
                    hash[board[i][j]]++;
            }
            for(auto it:hash)
            {
                if(it.second > 1)
                    return false;
            }
        }
        
        for(int i=0;i<9;i++)
        {
            unordered_map<char, int> hash;
            for(int j=0;j<9;j++)
            {
                if(board[j][i] != '.')
                    hash[board[j][i]]++;
            }
            for(auto it:hash)
            {
                if(it.second > 1)
                    return false;
            }
        }
        
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                unordered_map<char, int> hash;
                for(int p=i;p<i+3;p++)
                {
                    for(int q=j;q<j+3;q++)
                    {
                        if(board[p][q] != '.')
                            hash[board[p][q]]++;
                    }
                }
                for(auto it:hash)
                {
                    if(it.second > 1)
                        return false;
                }
            }   
        }
        
        return true;
    }
};