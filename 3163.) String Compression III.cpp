class Solution
{
public:
    string compressedString(string word)
    {
        int n = word.length();
        int counter = 1;
        string compressedStr = "";

        for (int i = 1; i < n; i++)
        {
            if (counter < 9 && word[i - 1] == word[i])
                counter++;
            else
            {
                compressedStr.push_back(counter + '0');
                compressedStr.push_back(word[i - 1]);
                counter = 1;
            }
        }

        compressedStr.push_back(counter + '0');
        compressedStr.push_back(word[n - 1]);

        return compressedStr;
    }
};