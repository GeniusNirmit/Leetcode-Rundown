class Solution
{
public:
    bool isOperator(char op)
    {
        return op == '+' || op == '*' || op == '-';
    }
    int computeOperation(int a, int b, char opr)
    {
        if (opr == '+')
            return a + b;
        else if (opr == '-')
            return a - b;
        return a * b;
    }
    vector<int> diffWaysToCompute(string expression)
    {
        int n = expression.length();
        vector<int> result;

        for (int i = 0; i < n; i++)
        {
            if (isOperator(expression[i]))
            {
                vector<int> result1 = diffWaysToCompute(expression.substr(0, i));
                vector<int> result2 = diffWaysToCompute(expression.substr(i + 1, n));

                int x = result1.size(), y = result2.size();

                for (int j = 0; j < x; j++)
                {
                    for (int k = 0; k < y; k++)
                        result.push_back(computeOperation(result1[j], result2[k], expression[i]));
                }
            }
        }

        if (result.size() == 0)
            result.push_back(stoi(expression));

        return result;
    }
};