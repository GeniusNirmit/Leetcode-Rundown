class Solution
{
public:
    int findSpecialInteger(vector<int> &a)
    {
        int n = a.size();
        int len = n / 4;

        for (int i = 0; i < n - len; i++)
        {
            if (a[i] == a[i + len])
                return a[i];
        }
        return -1;
    }
};