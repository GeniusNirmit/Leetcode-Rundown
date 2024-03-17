class Solution
{
public:
    int findMaxLength(vector<int> &a)
    {
        int n = a.size();
        int counter = 0, maxLength = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1)
                counter++;
            else
                counter--;

            if (mp.find(counter) != mp.end())
                maxLength = max(maxLength, i - mp[counter]);
            else
                mp[counter] = i;
        }
        return maxLength;
    }
};