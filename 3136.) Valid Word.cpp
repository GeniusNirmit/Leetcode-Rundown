class Solution
{
public:
    bool isValid(string word)
    {
        int n = word.length();
        bool isVowel = false, isConsonant = false;

        for (int i = 0; i < n; i++)
        {
            if (word[i] == '@' || word[i] == '#' || word[i] == '$')
                return false;
            if (word[i] == 'a' || word[i] == 'A' || word[i] == 'e' || word[i] == 'E' || word[i] == 'i' || word[i] == 'I' || word[i] == 'o' || word[i] == 'O' || word[i] == 'u' || word[i] == 'U')
                isVowel = true;
            else if (isupper(word[i]) || islower(word[i]))
                isConsonant = true;
        }

        if (isVowel && isConsonant && n >= 3)
            return true;
        return false;
    }
};