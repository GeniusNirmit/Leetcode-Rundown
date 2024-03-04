class Solution
{
public:
    vector<int> resultArray(vector<int> &a)
    {
        int n = a.size();
        vector<int> first, second;

        first.push_back(a[0]);
        second.push_back(a[1]);
        for (int i = 2; i < n; i++)
        {
            if (first[first.size() - 1] > second[second.size() - 1])
                first.push_back(a[i]);
            else
                second.push_back(a[i]);
        }

        for (int i = 0; i < second.size(); i++)
            first.push_back(second[i]);
        return first;
    }
};