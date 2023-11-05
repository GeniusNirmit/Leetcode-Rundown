class Solution
{
public:
    int findChampion(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> stronger(n);

        for (int i = 0; i < n; i++)
            stronger[i] = i;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && grid[i][j] == 1)
                    stronger[j] = stronger[i];
            }
        }

        int champion = stronger[0];
        for (int i = 1; i < n; i++)
        {
            if (stronger[i] != champion)
                return -1;
        }
        return champion;
    }
};