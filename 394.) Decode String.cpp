class Solution {
public:
    string decodeString(string s) {
        string answer;
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=']')
                st.push(s[i]);
            else
            {
                string test;
                while(st.top()!='[')
                {
                    test = st.top() + test;
                    st.pop();
                }
                st.pop();
                string number;
                while(!st.empty() && isdigit(st.top()))
                {
                    number = st.top() + number;
                    st.pop();
                }
                int num = stoi(number);
                while(num--)
                {
                    int i=0;
                    while(i<test.length())
                    {
                        st.push(test[i]);
                        i++;
                    }
                }
            }
        }
        while(!st.empty())
        {
            answer = st.top() + answer;
            st.pop();
        }
        return answer;
    }
};