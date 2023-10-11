class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
    {
        int n = flowers.size(), visits = people.size();
        vector<int> startTimes, endTimes;
        vector<int> fullBlooms(visits);

        for (int i = 0; i < n; i++)
        {
            startTimes.push_back(flowers[i][0]);
            endTimes.push_back(flowers[i][1] + 1);
        }
        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());

        for (int i = 0; i < visits; i++)
        {
            int startCounter = upper_bound(startTimes.begin(), startTimes.end(), people[i]) - startTimes.begin();
            int endCounter = upper_bound(endTimes.begin(), endTimes.end(), people[i]) - endTimes.begin();

            fullBlooms[i] = startCounter - endCounter;
        }
        return fullBlooms;
    }
};
