class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> combinations;
        vector<int> combination;

        findCombinations(combinations, combination, n, k, 1);
        return combinations;
    }
    void findCombinations(vector<vector<int>> &combinations, vector<int> &combination, int n, int k, int current)
    {
        if (combination.size() == k)
        {
            combinations.push_back(combination);
            return;
        }

        for (int i = current; i <= n; i++)
        {
            combination.push_back(i);
            findCombinations(combinations, combination, n, k, i + 1);
            combination.pop_back();
        }
        return;
    }
};