class Solution
{
    int MOD = 1e9 + 7;

public:
    int maximizeSquareArea(int m, int n, vector<int> &hFences, vector<int> &vFences)
    {
        long long maxArea = -1;
        unordered_set<int> hLengths;

        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        int hSize = hFences.size(), vSize = vFences.size();

        for (int i = 0; i < hSize; i++)
        {
            for (int j = i + 1; j < hSize; j++)
                hLengths.insert(hFences[j] - hFences[i]);
        }

        for (int i = 0; i < vSize; i++)
        {
            for (int j = i + 1; j < vSize; j++)
            {
                int vLength = vFences[j] - vFences[i];

                if (hLengths.find(vLength) != hLengths.end())
                    maxArea = max(maxArea, 1LL * vLength * vLength);
            }
        }
        return maxArea % MOD;
    }
};