class Solution
{
public:
    int minimumAddedCoins(vector<int> &coins, int target)
    {
        int n = coins.size();
        multiset<long> st;
        long num = 1;
        int counter = 0;

        for (int i = 0; i < n; i++)
            st.insert(coins[i]);

        while (num < target)
        {
            num = 1;
            for (long i : st)
            {
                if (num >= i)
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