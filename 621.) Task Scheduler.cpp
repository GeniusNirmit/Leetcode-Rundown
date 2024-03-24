class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int tasksSize = tasks.size();
        vector<int> mp(26, 0);
        int maximum = 0, maxCounter = 0;

        for (int i = 0; i < tasksSize; i++)
        {
            mp[tasks[i] - 'A']++;
            if (maximum == mp[tasks[i] - 'A'])
                maxCounter++;
            else if (maximum < mp[tasks[i] - 'A'])
            {
                maximum = mp[tasks[i] - 'A'];
                maxCounter = 1;
            }
        }

        int partCounter = maximum - 1;
        int partLength = n - (maxCounter - 1);
        int emptySlots = partCounter * partLength;
        int availableTasks = tasksSize - (maximum * maxCounter);
        int idleSlots = max(0, emptySlots - availableTasks);

        return tasksSize + idleSlots;
    }
};