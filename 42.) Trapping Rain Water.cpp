class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height.size());
        vector<int> right(height.size());
        int waterTrap = 0;
        left[0] = height[0];
        for(int i=1;i<height.size();i++)
        {
            if(left[i-1]>height[i])
                left[i] = left[i-1];
            else
                left[i] = height[i];
        }
        right[height.size()-1] = height[height.size()-1];   
        for(int i=height.size()-2;i>=0;i--)
        {
            if(right[i+1]>height[i])
                right[i] = right[i+1];
            else
                right[i] = height[i];
        }
        for(int i=1;i<height.size()-1;i++)
        {
            if(left[i]<right[i])
                waterTrap += left[i] - height[i];
            else
                waterTrap += right[i] - height[i];
        }
        return waterTrap;
    }
};