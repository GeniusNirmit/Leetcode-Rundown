class Solution
{
public:
    bool PredictTheWinner(vector<int> &a)
    {
        int n = a.size();
        int dp[n + 1][n + 1];


        if (maxDiff(a, 0, a.size() - 1, a.size()) >= 0)
            return true;
        return false;
    }
    int maxDiff(vector<int> &a, int left, int right, int n)
    {
        if (left == right)
            return a[left];

        int leftScore = a[left] - maxDiff(a, left + 1, right, n);
        int rightScore = a[right] - maxDiff(a, left, right - 1, n);

        cout << max(leftScore, rightScore) << endl;
        return max(leftScore, rightScore);
    }
};
