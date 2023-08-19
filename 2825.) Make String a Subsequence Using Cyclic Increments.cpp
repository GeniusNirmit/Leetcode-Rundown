class Solution
{
public:
    bool canMakeSubsequence(string str1, string str2)
    {
        int n = str1.length(), m = str2.length();
        int i = 0, j = 0;

        while (i < n && j < m)
        {
            if (str1[i] == str2[j] || str1[i] + 1 == str2[j] || (str1[i] == 'z' && str2[j] == 'a'))
                j++;
            i++;
        }
        if (j == m)
            return true;
        return false;
    }
};