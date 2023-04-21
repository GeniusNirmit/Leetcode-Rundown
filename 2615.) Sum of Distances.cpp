class Solution {
public:
    vector<long long> distance(vector<int>& a) {
        vector<long long> distances(a.size());
        unordered_map<int, vector<long long>> mp;

        for(int i=0; i<a.size(); i++)
            mp[a[i]].push_back(i);

        for(auto i: mp)
        {
            long long sum = 0;
            for(int j=1; j<i.second.size(); j++)
                sum += i.second[j] - i.second[0];
            
            distances[i.second[0]] = sum;
            for(int j=1; j<i.second.size(); j++)
            {
                sum += (i.second[j] - i.second[j - 1]) * (2*j - i.second.size());
                distances[i.second[j]] = sum;
            }
        }
        return distances;
    }
};
