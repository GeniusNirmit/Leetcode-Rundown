class Solution
{
public:
    bool isSubstringPresent(string s)
    {
        int n = s.length();
        unordered_set<string> st;

        for (int i = 1; i < n; i++)
        {
            string current = "";
            current += s[i - 1];
            current += s[i];
            st.insert(current);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            string current = "";
            current += s[i + 1];
            current += s[i];

            if (st.find(current) != st.end())
                return true;
        }
        return false;
    }
};