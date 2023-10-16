class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> triangle;
        triangle.push_back({1});

        for (int i = 1; i <= rowIndex; i++)
        {
            vector<int> row;
            row.push_back(1);

            for (int j = 1; j < i; j++)
                row.push_back(triangle[i - 1][j - 1] + triangle[i - 1][j]);

            row.push_back(1);
            triangle.push_back(row);
        }

        return triangle[rowIndex];
    }
};