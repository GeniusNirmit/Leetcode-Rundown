class Solution
{
public:
    bool hasTrailingZeros(vector<int> &a)
    {
        int n = a.size();
        int counter = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0)
                counter++;
            if (counter >= 2)
                return true;
        }
        return false;
    }
};