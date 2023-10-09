class Solution
{
public:
    int minProcessingTime(vector<int> &processorTime, vector<int> &tasks)
    {
        int processors = processorTime.size(), totalTasks = tasks.size();

        sort(tasks.begin(), tasks.end());
        sort(processorTime.rbegin(), processorTime.rend());

        int maxTime = 0;
        for (int i = 0; i < totalTasks; i++)
            maxTime = max(maxTime, tasks[i] + processorTime[i / 4]);
        return maxTime;
    }
};