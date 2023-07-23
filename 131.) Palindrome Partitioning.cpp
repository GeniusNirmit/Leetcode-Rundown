class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> permutations;
        vector<string> permutation;

        canPartite(s, 0, permutation, permutations);

        return permutations;
    }
    void canPartite(string s, int partition, vector<string>& permutation, vector<vector<string>>& permutations) {
        if(partition == s.length())
        {
            permutations.push_back(permutation);
            return;
        }

        for(int i=partition; i<s.length(); i++)
        {
            if(isPalindrome(s, partition, i))
            {
                permutation.push_back(s.substr(partition, i - partition + 1));
                canPartite(s, i + 1, permutation, permutations);
                permutation.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int start, int end) {
        while(start <= end)
        {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};