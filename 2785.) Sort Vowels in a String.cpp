class Solution
{
public:
    string sortVowels(string s)
    {
        int n = s.length();
        string updatedString = s;
        vector<char> vowels;

        for (int i = 0; i < n; i++)
        {
            if (isVowel(s[i]))
                vowels.push_back(s[i]);
        }

        sort(vowels.begin(), vowels.end());
        int j = 0;

        for (int i = 0; i < n; i++)
        {
            if (isVowel(s[i]))
            {
                updatedString[i] = vowels[j];
                j++;
            }
        }
        return updatedString;
    }
    bool isVowel(char ch)
    {
        if (ch == 'A' || ch == 'a')
            return true;
        else if (ch == 'E' || ch == 'e')
            return true;
        else if (ch == 'I' || ch == 'i')
            return true;
        else if (ch == 'O' || ch == 'o')
            return true;
        else if (ch == 'U' || ch == 'u')
            return true;
        return false;
    }
};