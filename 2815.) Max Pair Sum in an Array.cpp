class Solution
{
public:
    int maxSum(vector<int> &a)
    {
        int maximumSum = INT_MIN;
        int n = a.size();

        for (int i = 0; i < n; i++)
        {
            string num1 = to_string(a[i]);
            sort(num1.begin(), num1.end());
            for (int j = i + 1; j < n; j++)
            {
                string num2 = to_string(a[j]);
                sort(num2.begin(), num2.end());
                if (num1[num1.length() - 1] == num2[num2.length() - 1])
                    maximumSum = max(maximumSum, a[i] + a[j]);
            }
        }
        if (maximumSum == INT_MIN)
            return -1;
        return maximumSum;
    }
};