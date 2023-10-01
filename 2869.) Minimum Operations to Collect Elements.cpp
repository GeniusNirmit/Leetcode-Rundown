class Solution
{
public:
    int minOperations(vector<int> &a, int k)
    {
        int n = a.size();
        multiset<int> st;
        int operations;

        for (int i = n - 1; i >= 0; i--)
        {
            if (st.size() == k)
                break;
            if (a[i] <= k && st.find(a[i]) == st.end())
            {
                st.insert(a[i]);
                operations = n - i;
            }
        }
        return operations;
    }
};