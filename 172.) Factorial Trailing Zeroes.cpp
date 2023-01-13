class Solution {
public:
    int trailingZeroes(int n) {
        int counter = 0;
        while(n > 0)
        {
            counter += n/5;
            n /= 5;
        }
        return counter;
    }
};