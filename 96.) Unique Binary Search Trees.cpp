class Solution {
public:
    int numTrees(int n) {
        if(n <= 2)
            return n;
        
        long long uniqueTrees = 1;
        for(int i=2*n, j = 1; i >=n && j<=n; i--,j++)
        {
            uniqueTrees *= i;
            uniqueTrees /= j;
        }

        uniqueTrees /= (n+1);
        return uniqueTrees;
    }
};