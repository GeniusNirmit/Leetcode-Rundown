class Solution
{
public:
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        int m = sentence1.length(), n = sentence2.length();
        vector<string> words1, words2;

        string temp = "";
        for (int i = 0; i < m; i++)
        {
            if (sentence1[i] == ' ')
            {
                words1.push_back(temp);
                temp = "";
            }
            else
                temp += sentence1[i];
        }
        words1.push_back(temp);

        temp = "";
        for (int i = 0; i < n; i++)
        {
            if (sentence2[i] == ' ')
            {
                words2.push_back(temp);
                temp = "";
            }
            else
                temp += sentence2[i];
        }
        words2.push_back(temp);

        m = words1.size(), n = words2.size();

        if (m < n)
            return areSentencesSimilar(sentence2, sentence1);

        int start = 0, end1 = m - 1, end2 = n - 1;

        while (start < n && words1[start] == words2[start])
            start++;

        while (end2 >= 0 && words1[end1] == words2[end2])
        {
            end1--;
            end2--;
        }

        if (end2 < start)
            return true;
        return false;
    }
};