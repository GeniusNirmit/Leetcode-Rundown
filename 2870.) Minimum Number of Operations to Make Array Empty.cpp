class Solution
{
public:
    int minOperations(vector<int> &a)
    {
        unordered_map<int, int> mp;
        int n = a.size();
        int operations = 0;

        for (int i = 0; i < n; i++)
            mp[a[i]]++;

        for (auto i : mp)
        {
            if (i.second % 3 == 0)
                operations += i.second / 3;
            else if (i.second > 3 && i.second % 3 == 1)
            {
                if ((i.second - 4) % 3 == 0)
                    operations += (i.second - 4) / 3 + 2;
            }
            else if (i.second % 3 == 2)
                operations += i.second / 3 + 1;
            else
                return -1;
        }
        return operations;
    }
};