class Solution
{
public:
    int minOperations(vector<int> &a)
    {
        int n = a.size();
        int minCounter = n;
        set<int> st(a.begin(), a.end());
        vector<int> unique;

        for (auto i : st)
            unique.push_back(i);

        int i = 0;
        int uniques = unique.size();
        for (int j = 0; j < n; j++)
        {
            while (i < uniques && unique[i] < unique[j] + n)
                i++;

            minCounter = min(minCounter, n + j - i);
        }
        return minCounter;
    }
};
