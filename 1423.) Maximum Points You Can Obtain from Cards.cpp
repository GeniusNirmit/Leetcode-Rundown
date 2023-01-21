class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalPoints = 0;
        int maxPoints = 0;
        for(int i=0;i<k;i++)
            totalPoints += cardPoints[i];
        maxPoints = totalPoints;
        for(int i=k-1;i>=0;i--)
        {
            totalPoints -= cardPoints[i];
            totalPoints += cardPoints[cardPoints.size()-k+i];
            maxPoints = max(maxPoints, totalPoints);
        }
        return maxPoints;
    }
};+