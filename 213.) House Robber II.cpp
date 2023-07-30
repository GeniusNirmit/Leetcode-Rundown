class Solution
{
public:
    int rob(vector<int> &a)
    {
        if(a.size() == 1)
            return a[0];
            
        vector<int> firstElements, lastElements;

        for(int i = 0; i < a.size(); i++)   
        {
            if(i != a.size() - 1)
                firstElements.push_back(a[i]);
            if(i != 0)
                lastElements.push_back(a[i]);
        }
        return max(pickHouse(firstElements), pickHouse(lastElements));
    }
    int pickHouse(vector<int> &a)
    {
        int n = a.size();
        int prev = a[0];
        int prev2 = 0;

        for (int i = 1; i < n; i++)
        {
            int picked = a[i];
            if (i > 1)
                picked += prev2;

            int notPicked = prev;

            int current = max(picked, notPicked);
            prev2 = prev;
            prev = current;
        }

        return prev;
    }
};