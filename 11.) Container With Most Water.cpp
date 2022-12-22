class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int maximumArea = 0;
        while(i<j)
        {
            maximumArea = max(min(height[i],height[j])*(j-i),maximumArea);
            if(height[i]>height[j])
                j--;
            else
                i++;
        }
        return maximumArea;
    }
};