class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        int n = word.length(), counter = 0;
        vector<bool> upperCase(26, 0), lowerCase(26, 0);

        for (int i = 0; i < n; i++)
        {
            if (isupper(word[i]))
                upperCase[word[i] - 'A'] = true;
            else
                lowerCase[word[i] - 'a'] = true;
        }

        for (int i = 0; i < 26; i++)
        {
            if (upperCase[i] && lowerCase[i])
                counter++;
        }

        return counter;
    }
};