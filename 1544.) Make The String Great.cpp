class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            st.push(s[i]);
            while(!st.empty() && ((st.top()==(s[i+1]+32)) || (st.top()==(s[i+1]-32))))
            {
                st.pop();
                i++;
            }
        }
        s = "";
        while(!st.empty())
        {
            s = st.top() + s;
            st.pop();
        }
        return s;
    }
};