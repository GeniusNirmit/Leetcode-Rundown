class Solution {
public:
    int maxWidthRamp(vector<int>& a) {
        stack<int> st;
        int maxRamp = 0;
        st.push(0);
        for(int i=0;i<a.size();i++)
        {
            if(a[st.top()]>a[i])
                st.push(i);
        }
        for(int i=a.size()-1;i>=0;i--)
        {
            while(!st.empty() && a[st.top()]<=a[i])
            {
                if(maxRamp<i-st.top())
                    maxRamp = i-st.top();
                st.pop();
            }
        }
        return maxRamp;
    }
};