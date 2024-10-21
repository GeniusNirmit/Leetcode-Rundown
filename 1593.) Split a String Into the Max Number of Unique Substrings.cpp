class Solution
{
    int splitString(string s, unordered_set<string> &st, int ind)
    {
        int n = s.length();
        int counter = 0;

        if (ind == n)
            return counter;

        string temp = "";
        for (int i = ind; i < n; i++)
        {
            temp += s[i];

            if (st.find(temp) == st.end())
            {
                st.insert(temp);
                counter = max(counter, splitString(s, st, i + 1) + 1);
                st.erase(temp);
            }
        }

        return counter;
    }

public:
    int maxUniqueSplit(string s)
    {
        int n = s.length();
        unordered_set<string> st;

        return splitString(s, st, 0);
    }
};