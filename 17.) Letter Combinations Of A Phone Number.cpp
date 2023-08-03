class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> combinations, s;

        if (digits.length() == 0)
            return combinations;

        string combination;
        unordered_map<int, string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        for (int i = 0; i < digits.length(); i++)
            s.push_back(mp[digits[i] - '0']);

        findCombinations(digits.length(), 0, s, combinations, combination);
        return combinations;
    }
    void findCombinations(int size, int index, vector<string> s, vector<string> &combinations, string combination)
    {
        if (size == combination.length())
        {
            combinations.push_back(combination);
            return;
        }

        for (int i = 0; i < s[index].length(); i++)
        {
            combination.push_back(s[index][i]);
            findCombinations(size, index + 1, s, combinations, combination);
            combination.pop_back();
        }
        return;
    }
};