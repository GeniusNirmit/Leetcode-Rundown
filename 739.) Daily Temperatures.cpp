class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> v(temperatures.size(),0);
        for(int i=temperatures.size()-1;i>=0;i--)
        {
            while(!st.empty() && temperatures[st.top()]<=temperatures[i])
                st.pop();
            if(st.empty())
                v[i] = 0;
            else
                v[i] = st.top() - i;
            st.push(i);
        }
        return v;
    }
};