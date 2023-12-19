class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> smoothImage(m, vector<int>(n));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int average = 0, counter = 0;
                for (int x = i - 1; x <= i + 1; x++)
                {
                    for (int y = j - 1; y <= j + 1; y++)
                    {
                        if (x >= 0 && x < m && y >= 0 && y < n)
                        {
                            average += img[x][y];
                            counter++;
                        }
                    }
                }
                smoothImage[i][j] = average / counter;
            }
        }
        return smoothImage;
    }
};