class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& a) {
        unordered_map<int,int> mp;
        long long counter = a.size();
        for (int i = 0; i < a.size(); ++i)
            mp[a[i]] = i;

        sort(a.begin(), a.end());

        for (int i=1; i<a.size(); i++)
        {
            if (mp[a[i]] < mp[a[i-1]])
                counter += a.size() - i;
        }
        return counter;
    }
};