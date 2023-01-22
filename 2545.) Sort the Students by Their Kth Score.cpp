// Approach - 1

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        if(score[0].size() < k)
            return score;
        int n = score.size();
        vector<pair<int,int>> studentPair;
        vector<vector<int>> sortedMatrix;
        for(int i=0;i<n;i++)
            studentPair.push_back({score[i][k],i});
        sort(studentPair.begin(),studentPair.end());
        reverse(studentPair.begin(),studentPair.end());
        int i = 0;
        while(n--)
        {
            int x = studentPair[i].second;
            sortedMatrix.push_back(score[x]);
            i++;
        }
        return sortedMatrix;
    }
};

// Approach - 2

int k;
bool cmp(vector<int> a, vector<int> b) {
    return a[k] > b[k];
}
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        ::k = k;
        vector<vector<int>> sortedMatrix = score;
        sort(sortedMatrix.begin(),sortedMatrix.end(),cmp);
        return sortedMatrix;
    }
};