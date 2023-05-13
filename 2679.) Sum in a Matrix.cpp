class Solution {
public:
    int matrixSum(vector<vector<int>>& a) {
        int score = 0;
        for(int i=0; i<a.size(); i++)
            sort(a[i].begin(), a[i].end());

        for(int i=0; i<a[0].size(); i++)
        {
            int maxElement = a[0][i];
            for(int j=0; j<a.size(); j++)
                maxElement = max(a[j][i], maxElement);
            score += maxElement;
        }
        return score;
    }
};