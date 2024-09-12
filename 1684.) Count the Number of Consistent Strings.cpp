class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        int m = words.size();
        int counter = 0;
        unordered_set<char> st(allowed.begin(), allowed.end());

        for (int i = 0; i < m; i++)
        {
            bool flag = true;
            int n = words[i].length();
            for (int j = 0; j < n; j++)
            {
                if (st.find(words[i][j]) == st.end())
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
                counter++;
        }

        return counter;
    }
};