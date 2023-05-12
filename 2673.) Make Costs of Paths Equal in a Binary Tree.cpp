class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int counter = 0;
        dfs(1, n, cost, counter);
        return counter;
    }
    int dfs(int i, int n, vector<int>& cost, int& counter) {
        if(i > n)
            return 0;
        int left = dfs(2*i, n, cost, counter);
        int right = dfs(2*i + 1, n, cost, counter);
        counter += abs(left - right);
        return cost[i - 1] + max(left, right);
    }
};