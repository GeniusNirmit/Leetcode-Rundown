class Solution
{
public:
    string shortestBeautifulSubstring(string s, int k)
    {
        string beautifulString;
        vector<string> substrings;
        int n = s.length();
        int counter = 0, minLength = n + 1, ind1 = -1, ind2 = -1;

        int i = 0, j = 0;

        while (i < n)
        {
            if (s[i] == '1')
                counter++;
            while (counter >= k)
            {
                if (counter == k)
                {
                    if (minLength >= i - j + 1)
                    {
                        string substring = "";
                        if (minLength > i - j + 1)
                            substrings.clear();
                        minLength = i - j + 1;
                        ind1 = j;
                        ind2 = i;
                        for (int i = ind1; i <= ind2; i++)
                            substring += s[i];
                        substrings.push_back(substring);
                    }
                }
                if (s[j] == '1')
                    counter--;
                j++;
            }
            i++;
        }

        if (minLength == n + 1)
            return beautifulString;

        int totalSubstrings = substrings.size();
        beautifulString = substrings[0];
        for (int i = 1; i < totalSubstrings; i++)
        {
            if (beautifulString > substrings[i])
                beautifulString = substrings[i];
        }

        return beautifulString;
    }
};