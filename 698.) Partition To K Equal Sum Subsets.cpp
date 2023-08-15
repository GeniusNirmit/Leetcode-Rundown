class Solution
{
public:
    bool canPartitionKSubsets(vector<int> &a, int k)
    {
        int sum = 0;
        for (int i = 0; i < a.size(); i++)
            sum += a[i];

        if (sum % k != 0)
            return false;

        int n = a.size();
        sort(a.begin(), a.end(), greater<int>());
        vector<bool> visited(n, false);
        return canPartition(n, a, k, sum / k, 0, 0, visited);
    }
    bool canPartition(int n, vector<int> &a, int k, int target, int sum, int ind, vector<bool> &visited)
    {
        if (k == 1)
            return true;
        if (sum == target)
            return canPartition(n, a, k - 1, target, 0, 0, visited);
        if (ind >= n)
            return false;

        for (int i = ind; i < n; i++)
        {
            if (!visited[i] && sum + a[i] <= target)
            {
                visited[i] = true;
                if (canPartition(n, a, k, target, sum + a[i], i + 1, visited))
                    return true;
                visited[i] = false;
            }
        }
        return false;
    }
};
