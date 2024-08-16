class Solution
{
public:
    int maxDistance(vector<vector<int>> &a)
    {
        int n = a.size();
        int maxDist = INT_MIN;
        int maxVal = a[0][a[0].size() - 1];
        int minVal = a[0][0];

        for (int i = 1; i < n; i++)
        {
            int m = a[i].size();
            maxDist = max({maxDist, abs(a[i][0] - maxVal), abs(a[i][m - 1] - minVal)});
            maxVal = max(maxVal, a[i][m - 1]);
            minVal = min(minVal, a[i][0]);
        }

        return maxDist;
    }
};