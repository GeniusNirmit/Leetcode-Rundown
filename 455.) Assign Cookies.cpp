class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int contentChild = 0;
        int ind = 0;
        while (ind < s.size() && contentChild < g.size())
        {
            if (s[ind] >= g[contentChild])
                contentChild++;
            ind++;
        }
        return contentChild;
    }
};