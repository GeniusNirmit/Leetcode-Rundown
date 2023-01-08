class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()<3)
            return points.size();
        int currentPoints = 2,maxPoints = 2;
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                currentPoints = 2;
                for(int k=0;k<points.size();k++)
                {
                    if(k!=i && k!=j && ((points[k][0]-points[i][0])*(points[j][1]-points[i][1]))==((points[k][1]-points[i][1])*(points[j][0]-points[i][0])))
                        currentPoints++;
                }
                maxPoints = max(maxPoints,currentPoints);
            }
        }
        return maxPoints;
    }
};