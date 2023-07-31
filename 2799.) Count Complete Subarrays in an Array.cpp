class Solution
{
public:
    int countCompleteSubarrays(vector<int> &a)
    {
        unordered_set<int> st(a.begin(), a.end());
        unordered_map<int, int> mp;
        int i = 0, j = 0, counter = 0, n = a.size(), uniqueNums = st.size();

        while (i < n)
        {
            mp[a[i]]++;
            while (mp.size() == uniqueNums)
            {
                counter += n - i;
                mp[a[j]]--;
                if (mp[a[j]] == 0)
                    mp.erase(a[j]);
                j++;
            }
            i++;
        }
        return counter;
    }
};