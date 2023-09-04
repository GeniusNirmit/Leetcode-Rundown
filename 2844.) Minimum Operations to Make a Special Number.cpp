class Solution
{
public:
    int minimumOperations(string num)
    {
        int n = num.length();

        if (n == 1)
        {
            if (num == "0")
                return 0;
            return 1;
        }

        stack<char> st;

        for (int i = 0; i < n; i++)
            st.push(num[i]);

        int isFive = 0, isZero = 0;
        int counter = 0;

        while (!st.empty())
        {
            char num = st.top();

            if (num == '2' && isFive || num == '7' && isFive)
                return counter + isZero;
            else if (num == '0' && isZero || num == '5' && isZero)
                return counter + isFive;
            else if (num == '5' && !isFive)
                isFive = 1;
            else if (num == '0' && !isZero)
                isZero = 1;
            else
                counter++;
            st.pop();
        }
        return counter + isFive;
    }
};