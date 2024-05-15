class Solution
{
    bool isValidSafeness(vector<vector<int>> &grid, int safeFactor)
    {
        int n = grid.size();

        if (safeFactor > grid[0][0] || safeFactor > grid[n - 1][n - 1])
            return false;

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty())
        {
            pair<int, int> current = q.front();
            q.pop();

            if (current.first == n - 1 && current.second == n - 1)
                return true;

            vector<int> row{0, -1, 0, 1};
            vector<int> col{1, 0, -1, 0};

            for (int i = 0; i < 4; i++)
            {
                int delRow = current.first + row[i];
                int delCol = current.second + col[i];
                int currentVal = grid[current.first][current.second];

                if (delRow >= 0 && delRow < n && delCol >= 0 && delCol < n && !visited[delRow][delCol] && grid[delRow][delCol] >= safeFactor)
                {
                    visited[delRow][delCol] = true;
                    q.push({delRow, delCol});
                }
            }
        }

        return false;
    }

public:
    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int n = grid.size();
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    grid[i][j] = 0;
                }
                else
                    grid[i][j] = -1;
            }
        }

        vector<int> row{0, -1, 0, 1};
        vector<int> col{1, 0, -1, 0};

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                pair<int, int> current = q.front();
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int delRow = current.first + row[i];
                    int delCol = current.second + col[i];
                    int currentVal = grid[current.first][current.second];

                    if (delRow >= 0 && delRow < n && delCol >= 0 && delCol < n && grid[delRow][delCol] == -1)
                    {
                        grid[delRow][delCol] = currentVal + 1;
                        q.push({delRow, delCol});
                    }
                }
            }
        }

        int l = 0, h = 0, maxSafe = -1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                h = max(h, grid[i][j]);
        }

        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (isValidSafeness(grid, mid))
            {
                maxSafe = mid;
                l = mid + 1;
            }
            else
                h = mid - 1;
        }

        return maxSafe;
    }
};