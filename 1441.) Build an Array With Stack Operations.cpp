class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        int m = target.size();
        vector<string> operations;
        vector<bool> targetFlag(n, false);

        for (int i = 0; i < m; i++)
            targetFlag[target[i] - 1] = true;

        for (int i = 0; i < target[m - 1]; i++)
        {
            operations.push_back("Push");
            if (!targetFlag[i])
                operations.push_back("Pop");
        }

        return operations;
    }
};