class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int m = bank.size(), n = bank[0].size();
        int prevCounter = 0, currentCounter = 0;
        int totalBeams = 0;

        for (int i = 0; i < m; i++)
        {
            currentCounter = 0;
            for (int j = 0; j < n; j++)
            {
                if (bank[i][j] == '1')
                    currentCounter++;
            }
            if (currentCounter != 0)
            {
                totalBeams += (currentCounter * prevCounter);
                prevCounter = currentCounter;
            }
        }
        return totalBeams;
    }
};