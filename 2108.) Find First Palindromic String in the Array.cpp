class Solution
{
public:
    string firstPalindrome(vector<string> &words)
    {
        int n = words.size();

        for (int i = 0; i < n; i++)
        {
            bool isPalindrome = true;
            int start = 0, end = words[i].size() - 1;

            while (start <= end)
            {
                if (words[i][start] != words[i][end])
                {
                    isPalindrome = false;
                    break;
                }
                start++;
                end--;
            }

            if (isPalindrome)
                return words[i];
        }
        return "";
    }
};