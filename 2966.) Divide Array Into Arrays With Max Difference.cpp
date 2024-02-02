class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &a, int k)
    {
        int n = a.size();
        vector<vector<int>> dividedArray;

        sort(a.begin(), a.end());

        for (int i = 0; i < n; i += 3)
        {
            if (a[i + 2] - a[i] > k)
                return {};
            dividedArray.push_back({a[i], a[i + 1], a[i + 2]});
        }

        return dividedArray;
    }
};