class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int n = bills.size();
        int fiveCounter = 0;
        int tenCounter = 0;

        for (int i = 0; i < n; i++)
        {
            if (bills[i] == 5)
                fiveCounter++;
            else if (bills[i] == 10)
            {
                if (fiveCounter > 0)
                {
                    fiveCounter--;
                    tenCounter++;
                }
                else
                    return false;
            }
            else if (bills[i] == 20)
            {
                if (fiveCounter > 0 && tenCounter > 0)
                {
                    fiveCounter--;
                    tenCounter--;
                }
                else if (fiveCounter >= 3)
                    fiveCounter -= 3;
                else
                    return false;
            }
        }

        return true;
    }
};