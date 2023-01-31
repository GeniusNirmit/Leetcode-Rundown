class Solution {
public:
    int tribonacci(int n) {
        if(n==0)
            return 0;
        if(n==1 || n==2)
            return 1;
        vector<int> tribonacciValues(n+1);
        tribonacciValues[0] = 0;
        tribonacciValues[1] = 1;
        tribonacciValues[2] = 1;
        for(int i=3;i<=n;i++)
            tribonacciValues[i] = tribonacciValues[i-3] + tribonacciValues[i-2] + tribonacciValues[i-1];
        return tribonacciValues[n];
    }
};