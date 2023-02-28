class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length() <= k)
            return "0";
        if(k == 0)
            return num;
        stack<char> st;
        string newNumber = "";
        st.push(num[0]);
        for(int i=1;i<num.length();i++)
        {
            while(!st.empty() && k>0 && st.top() > num[i])
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
            if(st.size()==1 && num[i]=='0')
                st.pop();
        }
        while(!st.empty() && k--)
            st.pop();
        while(!st.empty())
        {
            newNumber += st.top();
            st.pop();
        }
        reverse(newNumber.begin(), newNumber.end());
        if(newNumber.length() == 0)
            return "0";
        return newNumber;
    }
};