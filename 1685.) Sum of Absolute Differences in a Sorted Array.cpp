class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &a)
    {
        int n = a.size();
        int sum = 0, leftSum = 0, rightSum = 0;
        vector<int> absDiff;

        for (int i = 0; i < n; i++)
            sum += a[i];

        for (int i = 0; i < n; i++)
        {
            rightSum = sum - leftSum - a[i];
            absDiff.push_back((a[i] * i - leftSum) + (rightSum - a[i] * (n - i - 1)));
            leftSum += a[i];
        }

        return absDiff;
    }
};