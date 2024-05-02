class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int n = word.length();

        string updatedWord = "";
        int ind = -1;
        for (int i = 0; i < n; i++)
        {
            if (word[i] == ch)
            {
                ind = i + 1;
                updatedWord += word[i];
                break;
            }
            else
                updatedWord += word[i];
        }

        if (ind == -1)
            return updatedWord;

        reverse(updatedWord.begin(), updatedWord.end());

        for (int i = ind; i < n; i++)
            updatedWord += word[i];

        return updatedWord;
    }
};