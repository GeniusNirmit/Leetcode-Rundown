class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &a)
    {
        int n = a.size();
        vector<int> sizes(n);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        int currentMaxVal = INT_MIN, minVal = 0, maxVal = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            pq.push({a[i][0], {i, 0}});
            sizes[i] = a[i].size();
            currentMaxVal = max(currentMaxVal, a[i][0]);
        }

        while (pq.size() == n)
        {
            int currentMinVal = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if (currentMaxVal - currentMinVal < maxVal - minVal)
            {
                maxVal = currentMaxVal;
                minVal = currentMinVal;
            }

            if (col + 1 < sizes[row])
            {
                pq.push({a[row][col + 1], {row, col + 1}});
                currentMaxVal = max(currentMaxVal, a[row][col + 1]);
            }
        }

        return {minVal, maxVal};
    }
};
Z