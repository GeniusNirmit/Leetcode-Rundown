class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& a) {
        stack<int> st;
        vector<int> updatedArray;
        st.push(a[0]);
        for(int i=1;i<a.size();i++)
        {
            if(__gcd(st.top(),a[i])==1)
                st.push(a[i]);
            else
            {
                int temp = lcm(st.top(),a[i]);
                st.pop();
                st.push(temp);
            }
            while(st.size() >= 2)
            {
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();
                if(__gcd(temp1,temp2) == 1)
                {
                    st.push(temp2);
                    st.push(temp1);
                    break;
                }
                else
                    st.push(lcm(temp1,temp2));
            }
        }
        while(!st.empty())
        {
            updatedArray.push_back(st.top());
            st.pop();
        }
        reverse(updatedArray.begin(),updatedArray.end());
        return updatedArray;
    }
};