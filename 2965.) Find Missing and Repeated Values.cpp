class Solution 
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int length = grid.size();
        vector<int> values(2);

        long n = length * length;

        long sum = (n * (n + 1)) / 2;
        long sqSum = (n * (n + 1) * (2 * n + 1)) / 6;

        long actualSum = 0, actualSqSum = 0;
        for(int i = 0; i < length; i++) {
            for(int j = 0; j < length; j++) {
                actualSum += grid[i][j];
                actualSqSum += (grid[i][j] * grid[i][j]);
            }
        }

        int val1 = actualSum - sum;
        int val2 = actualSqSum - sqSum;

        val2 = val2 / val1;

        values[0] = (val1 + val2) / 2;
        values[1] = val2 - values[0];

        return values;
    }
};