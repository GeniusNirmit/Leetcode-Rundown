class Solution
{
public:
    int longestCommonPrefix(vector<int> &a1, vector<int> &a2)
    {
        int m = a1.size(), n = a2.size();
        unordered_set<string> st;
        int maxLen = 0;

        for (int i = 0; i < m; i++)
        {
            string numStr = to_string(a1[i]);
            int len = numStr.length();
            for (int j = 0; j < len; j++)
                st.insert(numStr.substr(0, j + 1));
        }

        for (int i = 0; i < n; i++)
        {
            string numStr = to_string(a2[i]);
            int len = numStr.length();
            for (int j = 0; j < len; j++)
            {
                if (st.find(numStr.substr(0, j + 1)) != st.end())
                    maxLen = max(maxLen, j + 1);
            }
        }

        if (maxLen == 0)
            return 0;
        return maxLen;
    }
};