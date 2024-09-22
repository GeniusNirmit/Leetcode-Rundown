class Solution
{
public:
    void generateLexicalNumbers(int currentNum, int limit, vector<int> &lexicalNumbers)
    {
        if (currentNum > limit)
            return;

        lexicalNumbers.push_back(currentNum);

        for (int i = 0; i <= 9; i++)
        {
            int nextNum = currentNum * 10 + i;

            if (nextNum > limit)
                break;
            else
                generateLexicalNumbers(nextNum, limit, lexicalNumbers);
        }
    }
    vector<int> lexicalOrder(int n)
    {
        vector<int> lexicalNumbers;

        for (int i = 1; i <= 9; i++)
            generateLexicalNumbers(i, n, lexicalNumbers);

        return lexicalNumbers;
    }
};