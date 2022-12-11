class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        stack<int> st;
        vector<int> nextGreaterElement(a.size(),-1);
        for(int i=2*a.size()-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=a[i%a.size()])
                st.pop();
            if(!st.empty() && st.top()>a[i%a.size()])
                nextGreaterElement[i%a.size()] = st.top();
            st.push(a[i%a.size()]);
        }
        return nextGreaterElement;
    }
};