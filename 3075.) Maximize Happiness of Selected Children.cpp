class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        int n = happiness.size();
        sort(happiness.begin(), happiness.end());
        long long sum = 0;

        for (int i = n - 1; k-- && i >= 0; i--)
        {
            long long currentHappiness = happiness[i] - (n - 1 - i);

            if (currentHappiness > 0)
                sum += currentHappiness;
        }

        return sum;
    }
};