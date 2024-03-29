class Solution
{
public:
    vector<int> findDuplicates(vector<int> &a)
    {
        int n = a.size();
        vector<int> duplicates;

        for (int i = 0; i < n; i++)
        {
            if (a[abs(a[i]) - 1] < 0)
                duplicates.push_back(abs(a[i]));
            else
                a[abs(a[i]) - 1] = -a[abs(a[i]) - 1];
        }

        return duplicates;
    }
};