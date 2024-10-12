class Solution
{
public:
    vector<vector<long long>> splitPainting(vector<vector<int>> &segments)
    {
        int n = segments.size();
        vector<vector<long long>> painting;
        map<long long, long long> mp;
        long long sum = 0, prevSegmentEnd = 0;

        for (int i = 0; i < n; i++)
        {
            mp[segments[i][0]] += segments[i][2];
            mp[segments[i][1]] -= segments[i][2];
        }

        for (auto i : mp)
        {
            if (sum != 0)
                painting.push_back({prevSegmentEnd, i.first, sum});

            sum += i.second;
            prevSegmentEnd = i.first;
        }

        return painting;
    }
};