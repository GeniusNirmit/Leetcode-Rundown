class Solution
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        int timeSlot = minutesToTest / minutesToDie;
        timeSlot += 1;
        int pigs = 0;
        int time = 1;
        while (time < buckets)
        {
            time *= timeSlot;
            pigs++;
        }
        return pigs;
    }
};