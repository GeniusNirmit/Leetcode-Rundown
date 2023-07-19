class Solution {
public:
    vector<vector<int>> permute(vector<int>& a) {
        vector<vector<int>> permutations;
        vector<int> permutation;

        generatePermutation(0, a, permutations, permutation);
        return permutations;
    }
    void generatePermutation(int index, vector<int>& a, vector<vector<int>>& permutations, vector<int>& permutation) {
        if(index == a.size())
            return;
        
        for(int i=index; i<a.size(); i++)
        {
            permutation.push_back(a[i]);
            swap(a[index], a[i]);
            generatePermutation(index + 1, a, permutations, permutation);
            if(permutation.size() == a.size())
                permutations.push_back(permutation);
            permutation.pop_back();
            swap(a[index], a[i]);
        }
    }
};