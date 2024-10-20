class Solution
{
public:
    bool parseBoolExpr(string expression)
    {
        int n = expression.length();
        stack<char> st;

        for (int i = 0; i < n; i++)
        {
            if (expression[i] == '!' || expression[i] == '&' || expression[i] == '|' || expression[i] == 't' || expression[i] == 'f')
                st.push(expression[i]);

            if (expression[i] == ')')
            {
                bool trueVal = false, falseVal = false;

                while (st.top() == 't' || st.top() == 'f')
                {
                    if (st.top() == 't')
                        trueVal = true;
                    if (st.top() == 'f')
                        falseVal = true;
                    st.pop();
                }

                if (st.top() == '!')
                {
                    st.pop();
                    if (trueVal)
                        st.push('f');
                    else
                        st.push('t');
                }

                if (st.top() == '&')
                {
                    st.pop();
                    if (falseVal)
                        st.push('f');
                    else
                        st.push('t');
                }

                if (st.top() == '|')
                {
                    st.pop();
                    if (trueVal)
                        st.push('t');
                    else
                        st.push('f');
                }
            }
        }

        if (st.top() == 't')
            return true;
        return false;
    }
};