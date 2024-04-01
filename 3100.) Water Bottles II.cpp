class Solution
{
public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        int emptyBottles = numBottles, drunkBottles = numBottles;
        numBottles = 0;

        while (emptyBottles >= numExchange)
        {
            emptyBottles -= numExchange;
            numExchange++;
            emptyBottles++;
            drunkBottles++;
        }

        return drunkBottles;
    }
};