class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        int n = dist.size();
        int counter = 0;
        vector<int> time(n);

        for (int i = 0; i < n; i++)
            time[i] = ceil(double(dist[i]) / speed[i]);

        sort(time.begin(), time.end());

        for (int i = 0; i < n; i++)
        {
            if (i >= time[i])
                return counter;
            counter++;
        }
        return counter;
    }
};