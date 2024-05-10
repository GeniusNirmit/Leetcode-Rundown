class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &a, int k)
    {
        int n = a.size();
        priority_queue<pair<double, pair<int, int>>> pq;

        for (int i = 0; i < n; i++)
            pq.push({-1.0 * a[i] / a[n - 1], {i, n - 1}});

        k--;
        while (k--)
        {
            pair<int, int> current = pq.top().second;
            int num = current.first, deno = current.second;
            deno--;
            pq.pop();

            pq.push({-1.0 * a[num] / a[deno], {num, deno}});
        }

        int num = pq.top().second.first, deno = pq.top().second.second;
        return {a[num], a[deno]};
    }
};