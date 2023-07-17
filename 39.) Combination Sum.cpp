class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> combination;

        dfs(0, target, candidates, combinations, combination);
        return combinations;
    }

    void dfs(int index, int target, vector<int>& candidates, vector<vector<int>>& combinations, vector<int>& combination) {
        if(index == candidates.size())
        {
            if(target == 0)
                combinations.push_back(combination);
            return;
        }

        if(candidates[index] <= target)
        {
            combination.push_back(candidates[index]);
            dfs(index, target - candidates[index], candidates, combinations, combination);
            combination.pop_back();
        }

        dfs(index + 1, target, candidates, combinations, combination);
    }
};