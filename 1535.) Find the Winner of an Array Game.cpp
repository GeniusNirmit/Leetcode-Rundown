class Solution
{
public:
    int getWinner(vector<int> &a, int k)
    {
        int n = a.size();
        int maxVal = a[0];
        for (int i = 1; i < n; i++)
            maxVal = max(maxVal, a[i]);

        int winner = a[0];
        int winCounter = 0;
        for (int i = 1; i < n; i++)
        {
            if (winner > a[i])
                winCounter++;
            else
            {
                winner = a[i];
                winCounter = 1;
            }
            if (winCounter == k || winner == maxVal)
                return winner;
        }
        return -1;
    }
};