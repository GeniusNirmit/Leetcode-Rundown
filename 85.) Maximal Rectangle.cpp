class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> heights(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        vector<int> left(heights.size());
        vector<int> right(heights.size());
        int largestArea = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            while (!st.empty() && heights[i] <= heights[st.top()])
                st.pop();
            if (!st.empty())
                left[i] = st.top() + 1;
            else
                left[i] = 0;
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = heights.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[i] <= heights[st.top()])
                st.pop();
            if (!st.empty())
                right[i] = st.top() - 1;
            else
                right[i] = heights.size() - 1;
            st.push(i);
        }
        for (int i = 0; i < heights.size(); i++)
        {
            if (largestArea < (right[i] - left[i] + 1) * heights[i])
                largestArea = (right[i] - left[i] + 1) * heights[i];
        }
        return largestArea;
    }
};