class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a1, vector<int>& a2) {
        stack<int> st;
        unordered_map<int,int> nextGreaterElement;
        vector<int> v;
        for(int i=a2.size()-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=a2[i])
                st.pop();
            if(!st.empty() && st.top()>a2[i])
                nextGreaterElement[a2[i]] = st.top();
            else
                nextGreaterElement[a2[i]] = -1;
            st.push(a2[i]);
        }
        for(int i=0;i<a1.size();i++)
            v.push_back(nextGreaterElement.find(a1[i])->second);
        return v;
    }
};