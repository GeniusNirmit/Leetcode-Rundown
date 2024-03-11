class Solution
{
public:
    int minimumBoxes(vector<int> &apple, vector<int> &capacity)
    {
        int n = apple.size(), m = capacity.size();
        sort(capacity.begin(), capacity.end());
        int totalApples = 0, counter = 0;

        for (int i = 0; i < n; i++)
            totalApples += apple[i];

        int i = m - 1;
        while (totalApples > 0 && i >= 0)
        {
            totalApples -= capacity[i];
            counter++;
            i--;
        }

        return counter;
    }
};