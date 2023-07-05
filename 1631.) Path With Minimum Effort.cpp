class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> absDiffs(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        priority_queue<pair<int, int>> pq;

        pq.push({ 0, 0});
        absDiffs[0][0] = 0;

        vector<int> delRow{ 0, 1, 0, -1};
        vector<int> delCol{ 1, 0, -1, 0};

        while(!pq.empty())
        {
            int x = pq.top().first;
            int y = pq.top().second;
            pq.pop();
            int currentDiff = absDiffs[x][y];

            for(int i=0; i<4; i++)
            {
                int delX = x + delRow[i];
                int delY = y + delCol[i];

                if(delX >= 0 && delX < heights.size() && delY >= 0 && delY < heights[0].size())
                {
                    int newDiff = max(currentDiff, abs(heights[x][y] - heights[delX][delY]));
                    if(newDiff < absDiffs[delX][delY])
                    {
                        absDiffs[delX][delY] = newDiff;
                        pq.push({ delX, delY});
                    }
                } 
            }
        } 
        
        return absDiffs[heights.size() - 1][heights[0].size() - 1];
    }
};