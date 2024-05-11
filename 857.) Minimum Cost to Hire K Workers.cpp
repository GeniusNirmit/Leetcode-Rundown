class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        int n = quality.size();
        double totalCost = INT_MAX;
        double currentTotalQuality = 0;
        vector<pair<double, int>> wageToQualityRatio;
        priority_queue<int> highestQualityWorkers;

        for (int i = 0; i < n; i++)
            wageToQualityRatio.push_back({(double)wage[i] / quality[i], quality[i]});

        sort(wageToQualityRatio.begin(), wageToQualityRatio.end());

        for (int i = 0; i < n; i++)
        {
            highestQualityWorkers.push(wageToQualityRatio[i].second);
            currentTotalQuality += wageToQualityRatio[i].second;

            if (highestQualityWorkers.size() > k)
            {
                currentTotalQuality -= highestQualityWorkers.top();
                highestQualityWorkers.pop();
            }

            if (highestQualityWorkers.size() == k)
                totalCost = min(totalCost, currentTotalQuality * wageToQualityRatio[i].first);
        }

        return totalCost;
    }
};