class Solution
{
public:
    int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
    {
        int n = dimensions.size();
        vector<double> diagonals;
        double maxDiagonal = 0, maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            double diagonal = sqrt(((dimensions[i][0] * dimensions[i][0] * 1.0) + (dimensions[i][1] * dimensions[i][1] * 1.0)));
            diagonals.push_back(diagonal);
        }

        for (int i = 0; i < n; i++)
        {
            if (diagonals[i] > maxDiagonal)
            {
                maxDiagonal = diagonals[i];
                maxArea = dimensions[i][0] * dimensions[i][1];
            }
            else if (diagonals[i] == maxDiagonal && maxArea < (dimensions[i][0] * dimensions[i][1]))
                maxArea = (dimensions[i][0] * dimensions[i][1]);
        }
        return maxArea;
    }
};