class Solution
{
public:
    string solveFraction(string frac1, string frac2)
    {
        int num1, num2, deno1, deno2;
        int n1 = frac1.length(), n2 = frac2.length();

        int i = 0;
        string temp = "";
        if (frac1[0] == '-')
            i = 1;
        while (i < n1 && frac1[i] != '/')
        {
            temp += frac1[i];
            i++;
        }
        num1 = stoi(temp);

        if (frac1[0] == '-')
            num1 = -num1;

        i++;
        temp = "";
        while (i < n1)
        {
            temp += frac1[i];
            i++;
        }
        deno1 = stoi(temp);

        i = 0;
        temp = "";
        while (i < n2 && frac2[i] != '/')
        {
            temp += frac2[i];
            i++;
        }
        num2 = stoi(temp);

        i++;
        temp = "";
        while (i < n2)
        {
            temp += frac2[i];
            i++;
        }
        deno2 = stoi(temp);

        int newNum, newDeno;
        newNum = (num1 * deno2) + (num2 * deno1);
        newDeno = deno1 * deno2;

        int gcd = __gcd(abs(newNum), abs(newDeno));
        newNum /= gcd;
        newDeno /= gcd;

        if (newNum == 0)
            newDeno = 1;

        string fraction = "";
        fraction += to_string(newNum);
        fraction += '/';
        fraction += to_string(newDeno);

        return fraction;
    }
    string fractionAddition(string expression)
    {
        int n = expression.length();
        stack<string> st;
        int prev = 0;

        for (int i = 1; i < n; i++)
        {
            if (expression[i] == '-' || expression[i] == '+')
            {
                if (expression[prev] == '+')
                    st.push(expression.substr(prev + 1, i - prev));
                else
                    st.push(expression.substr(prev, i - prev));

                prev = i;
            }
        }
        if (expression[prev] == '+')
            st.push(expression.substr(prev + 1, n - prev));
        else
            st.push(expression.substr(prev, n - prev));

        while (st.size() > 1)
        {
            string frac1 = st.top();
            st.pop();

            string frac2 = st.top();
            st.pop();

            st.push(solveFraction(frac1, frac2));
        }

        return st.top();
    }
};