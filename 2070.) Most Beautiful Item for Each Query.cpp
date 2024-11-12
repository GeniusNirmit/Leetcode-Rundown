class Solution
{
public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
    {
        int n = queries.size(), m = items.size();
        vector<int> maxBeauties(n);
        vector<pair<int, int>> sortedQueries;

        for (int i = 0; i < n; i++)
            sortedQueries.push_back({queries[i], i});

        sort(sortedQueries.begin(), sortedQueries.end());
        sort(items.begin(), items.end());
        int ind = 0;
        int maxBeauty = -1;

        for (int i = 0; i < n; i++)
        {
            while (ind < m && sortedQueries[i].first >= items[ind][0])
            {
                maxBeauty = max(maxBeauty, items[ind][1]);
                ind++;
            }

            if (maxBeauty == -1)
                maxBeauties[sortedQueries[i].second] = 0;
            else
                maxBeauties[sortedQueries[i].second] = maxBeauty;
        }

        return maxBeauties;
    }
};