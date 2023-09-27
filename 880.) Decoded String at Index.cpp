class Solution
{
public:
    string decodeAtIndex(string s, int k)
    {
        int n = s.length();
        long long decodedSize = 0;
        string decoded = "";

        for (int i = 0; i < n; i++)
        {
            if (isdigit(s[i]))
                decodedSize *= s[i] - '0';
            else
                decodedSize++;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            k %= decodedSize;
            if (!k && !isdigit(s[i]))
            {
                decoded += s[i];
                return decoded;
            }

            if (isdigit(s[i]))
                decodedSize /= s[i] - '0';
            else
                decodedSize--;
        }
        return decoded;
    }
};