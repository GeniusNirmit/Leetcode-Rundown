class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());

        dfs(0, target, candidates, combinations, combination);
        return combinations;
    }
    void dfs(int index, int target, vector<int>& candidates, vector<vector<int>>& combinations, vector<int>& combination) {
        if(target == 0)
        {
            combinations.push_back(combination);
            return;
        }
        
        for(int i=index; i<candidates.size(); i++)
        {
            if(i > index && candidates[i] == candidates[i-1])
                continue;
            if(candidates[i] > target)
                break;
            combination.push_back(candidates[i]);
            dfs(i + 1, target - candidates[i], candidates, combinations, combination);
            combination.pop_back();
        }
    }
};