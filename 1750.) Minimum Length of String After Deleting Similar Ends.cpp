class Solution
{
public:
    int minimumLength(string s)
    {
        int n = s.length();
        int start = 0, end = n - 1;

        while (start < end && s[start] == s[end])
        {
            char current = s[start];

            while (start <= end && s[start] == current)
                start++;

            while (start < end && s[end] == current)
                end--;
        }

        return end - start + 1;
    }
};