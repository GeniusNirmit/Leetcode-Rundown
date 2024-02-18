class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        int i;
        for (i = 1; i < n; i++)
        {
            if (heights[i] - heights[i - 1] > 0)
            {
                pq.push(heights[i] - heights[i - 1]);
                if (pq.size() > ladders)
                {
                    bricks -= pq.top();
                    pq.pop();
                    if (bricks < 0)
                        break;
                }
            }
        }
        return i - 1;
    }
};