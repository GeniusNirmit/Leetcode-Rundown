class Solution
{
public:
    int maximumLength(string s)
    {
        int n = s.length();
        vector<string> substrings;
        unordered_map<string, int> mp;
        int maxLength = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
                substrings.push_back(s.substr(i, j - i));
        }

        for (auto i : substrings)
        {
            unordered_set<char> st(i.begin(), i.end());

            if (st.size() == 1)
                mp[i]++;
        }

        for (auto i : mp)
        {
            string current = i.first;
            if (i.second >= 3 && i.first.length() > maxLength)
                maxLength = i.first.length();
        }

        if (!maxLength)
            return -1;
        return maxLength;
    }
};