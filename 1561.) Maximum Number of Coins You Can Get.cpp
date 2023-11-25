class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        int n = piles.size();
        int counter = 0;
        sort(piles.begin(), piles.end());

        for (int i = n / 3; i < n; i += 2)
            counter += piles[i];
        return counter;
    }
};