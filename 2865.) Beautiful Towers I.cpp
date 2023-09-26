class Solution
{
public:
    long long maximumSumOfHeights(vector<int> &maxHeights)
    {
        int n = maxHeights.size();
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            long long currentSum = maxSum(n, maxHeights, i);
            if (currentSum > sum)
                sum = currentSum;
        }
        return sum;
    }
    long long maxSum(int &n, vector<int> &maxHeights, int ind)
    {
        int i = ind;
        long long sum = 0;
        long long prev = maxHeights[ind];
        while (i--)
        {
            long long current = maxHeights[i];
            if (current > prev)
                current = prev;
            sum += current;
            prev = current;
        }

        i = ind;
        prev = maxHeights[ind];
        while (i < n)
        {
            long long current = maxHeights[i];
            if (current > prev)
                current = prev;
            sum += current;
            prev = current;
            i++;
        }

        return sum;
    }
};