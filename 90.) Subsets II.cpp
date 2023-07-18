class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        vector<vector<int>> subsets;
        vector<int> subset;

        sort(a.begin(), a.end());
        findSubsets(0, a, subsets, subset);
        return subsets;
    }

    void findSubsets(int index, vector<int>& a, vector<vector<int>>& subsets, vector<int>& subset) {
        subsets.push_back(subset);

        for(int i=index; i<a.size(); i++)
        {
            if(i != index && a[i] == a[i-1])
                continue;
            subset.push_back(a[i]);
            findSubsets(i + 1, a, subsets, subset);
            subset.pop_back();
        }
    }
};