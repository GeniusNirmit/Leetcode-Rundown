class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        vector<int> left(heights.size());
        vector<int> right(heights.size());
        int largestArea = 0;
        for(int i=0;i<heights.size();i++)
        {
            while(!st.empty() && heights[i]<=heights[st.top()])
                st.pop();
            if(!st.empty())
                left[i] = st.top()+1;
            else
                left[i] = 0;
            st.push(i);
        }

        while(!st.empty())
            st.pop();

        for(int i=heights.size()-1;i>=0;i--)
        {
            while(!st.empty() && heights[i]<=heights[st.top()])
                st.pop();
            if(!st.empty())
                right[i] = st.top()-1;
            else
                right[i] = heights.size()-1;
            st.push(i);
        }
        for(int i=0;i<heights.size();i++)
        {
            if(largestArea < (right[i]-left[i]+1)*heights[i])
                largestArea = (right[i]-left[i]+1)*heights[i];
        }
        return largestArea;
    }
};