class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        int n = word.length(), counter = 0;
        vector<int> upperCase(26, -1), lowerCase(26, -1);

        for (int i = 0; i < n; i++)
        {
            if (isupper(word[i]) && upperCase[word[i] - 'A'] == -1)
                upperCase[word[i] - 'A'] = i;
            else if (islower(word[i]))
                lowerCase[word[i] - 'a'] = i;
        }

        for (int i = 0; i < 26; i++)
        {
            if (upperCase[i] != -1 && lowerCase[i] != -1 && upperCase[i] > lowerCase[i])
                counter++;
        }

        return counter;
    }
};