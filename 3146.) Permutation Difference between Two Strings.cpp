class Solution
{
public:
    int findPermutationDifference(string s, string t)
    {
        int n = s.length();
        int sum = 0;
        vector<int> ind1(26, 0), ind2(26, 0);

        for (int i = 0; i < n; i++)
            ind1[s[i] - 'a'] = i;

        for (int i = 0; i < n; i++)
            ind2[t[i] - 'a'] = i;

        for (int i = 0; i < 26; i++)
            sum += abs(ind1[i] - ind2[i]);
        return sum;
    }
};