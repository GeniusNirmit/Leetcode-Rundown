class Solution
{
public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        int m = land.size(), n = land[0].size();
        vector<vector<int>> farmlands;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (land[i][j] == 1)
                {
                    int x = i, y = j;
                    for (x = i; x < m && land[x][j] == 1; x++)
                    {
                        for (y = j; y < n && land[x][y] == 1; y++)
                        {
                            land[x][y] = -1;
                        }
                    }

                    farmlands.push_back({i, j, x - 1, y - 1});
                }
            }
        }

        return farmlands;
    }
};