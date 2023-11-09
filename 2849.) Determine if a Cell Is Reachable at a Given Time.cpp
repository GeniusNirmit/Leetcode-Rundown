class Solution
{
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        int height = abs(sy - fy);
        int width = abs(sx - fx);

        if (width == 0 && height == 0 && t == 1)
            return false;
        if (max(width, height) <= t)
            return true;
        return false;
    }
};