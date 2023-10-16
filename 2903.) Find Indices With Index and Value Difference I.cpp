class Solution
{
public:
    vector<int> findIndices(vector<int> &a, int indexDifference, int valueDifference)
    {
        int n = a.size();
        vector<int> indices(2, -1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (abs(i - j) >= indexDifference && abs(a[i] - a[j]) >= valueDifference)
                {
                    indices[0] = i;
                    indices[1] = j;
                    break;
                }
            }
        }

        return indices;
    }
};