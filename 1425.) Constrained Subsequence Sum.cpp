class Solution
{
public:
    int constrainedSubsetSum(vector<int> &a, int k)
    {
        int sum = a[0], n = a.size();
        priority_queue<pair<int, int>> pq;
        pq.push({a[0], 0});

        for (int i = 1; i < n; i++)
        {
            while (i - pq.top().second > k)
                pq.pop();

            int currentSum = max(0, pq.top().first) + a[i];
            sum = max(sum, currentSum);
            pq.push({currentSum, i});
        }
        return sum;
    }
};