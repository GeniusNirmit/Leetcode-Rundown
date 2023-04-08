class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b) {
        return a.first > b.first;
    }
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        vector<pair<int, int>> rewardDiff;
        vector<bool> visited(reward1.size(), false);
        int maxSum = 0;

        for(int i=0; i<reward1.size(); i++)
            rewardDiff.push_back({ reward1[i] - reward2[i], i});
        
        sort(rewardDiff.begin(), rewardDiff.end(), cmp);
        
        for(int i=0; i<k; i++)
        {
            visited[rewardDiff[i].second] = true;
            maxSum += reward1[rewardDiff[i].second];
        }

        for(int i=0; i<reward1.size(); i++)
        {
            if(!visited[i])
                maxSum += reward2[i];
        }
        return maxSum;
    }
};