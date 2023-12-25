class Solution
{
public:
    vector<int> numberGame(vector<int> &a)
    {
        if (a.size() == 1)
            return a;

        int n = a.size();
        sort(a.begin(), a.end());
        vector<int> minElements;

        int i = 0, j = 1;
        while (i < n && j < n)
        {
            minElements.push_back(a[j]);
            minElements.push_back(a[i]);
            j += 2;
            i += 2;
        }
        return minElements;
    }
};