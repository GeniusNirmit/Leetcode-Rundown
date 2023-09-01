class Solution
{
public:
    int jump(vector<int> &a)
    {
        int counter = 0, n = a.size();
        vector<int> maxReach;

        maxReach.push_back(a[0]);

        for (int i = 1; i < n; i++)
            maxReach.push_back(max(maxReach[i - 1], i + a[i]));

        int size = maxReach.size(), i = 0;
        while (i < size - 1)
        {
            counter++;
            i = maxReach[i];
        }
        return counter;
    }
};