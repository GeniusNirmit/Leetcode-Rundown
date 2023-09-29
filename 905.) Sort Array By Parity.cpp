class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &a)
    {
        int n = a.size();
        int i = 0, j = 0;

        while (i < n)
        {
            if (a[i] % 2 == 0)
            {
                swap(a[i], a[j]);
                j++;
            }
            i++;
        }
        return a;
    }
};