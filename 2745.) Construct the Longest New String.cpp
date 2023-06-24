class Solution {
public:
    int longestString(int x, int y, int z) {
        if(x > y)
            return (z + (2 * y + 1)) * 2;
        else if(x < y)
            return (z + (2 * x + 1)) * 2;
        else
            return (x + y + z) * 2;
    }
};