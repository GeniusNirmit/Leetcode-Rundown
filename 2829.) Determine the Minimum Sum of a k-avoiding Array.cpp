class Solution
{
public:
    int minimumSum(int n, int k)
    {
        unordered_set<int> st;
        int sum = 0, i = 1;

        while (st.size() < n)
        {
            auto findElement = st.find(k - i);
            if ((findElement != st.end() && *findElement == i) || findElement == st.end())
            {
                sum += i;
                st.insert(i);
            }
            i++;
        }

        return sum;
    }
};