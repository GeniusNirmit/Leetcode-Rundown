class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& a) {
        vector<vector<int>> permutations;
        map<vector<int>, int> mp;
        vector<int> permutation;

        generatePermutation(0, a, mp, permutation);

        for(auto i: mp)
            permutations.push_back(i.first);
        return permutations;
    }
    void generatePermutation(int index, vector<int>& a, map<vector<int>, int>& mp, vector<int>& permutation) {
        if(index == a.size())
            return;
        
        for(int i=index; i<a.size(); i++)
        {
            permutation.push_back(a[i]);
            swap(a[index], a[i]);
            generatePermutation(index + 1, a, mp, permutation);
            if(permutation.size() == a.size())
                mp[permutation]++;
            permutation.pop_back();
            swap(a[index], a[i]);
        }
    }
};