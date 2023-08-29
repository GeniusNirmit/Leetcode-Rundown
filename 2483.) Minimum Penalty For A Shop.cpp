class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int YCounter = 0, NCounter = 0;
        int n = customers.length();

        for (int i = 0; i < n; i++)
        {
            if (customers[i] == 'Y')
                YCounter++;
        }

        int minPenalty = YCounter + NCounter, penaltyTime = 0;

        for (int i = 0; i < n; i++)
        {
            if (customers[i] == 'Y')
                YCounter--;
            else
                NCounter++;

            if (minPenalty > YCounter + NCounter)
            {
                minPenalty = YCounter + NCounter;
                penaltyTime = i + 1;
            }
        }
        return penaltyTime;
    }
};