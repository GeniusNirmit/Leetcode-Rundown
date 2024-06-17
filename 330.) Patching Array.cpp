class Solution
{
public:
    int minPatches(vector<int> &a, int target)
    {
        int n = a.size();
        int counter = 0;
        multiset<long> st;

        for (int i = 0; i < n; i++)
            st.insert(a[i]);

        long num = 1;
        while (num < target)
        {
            num = 1;
            for (long i : st)
            {
                if (i <= num)
                    num += i;
                else
                    break;
            }

            if (num <= target)
            {
                counter++;
                st.insert(num);
            }
        }

        return counter;
    }
};