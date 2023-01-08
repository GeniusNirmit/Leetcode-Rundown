class Solution {
public:
    long long maxKelements(vector<int>& a, int k) {
        multiset<int> values(a.begin(),a.end());
        long long score = 0;
        while(k--)
        {
            auto element = values.rbegin();
            int temp = *element;
            values.erase(values.find(temp));
            score += temp;
            temp = ceil(temp/3.0);
            values.insert(temp);
        }
        return score;
    }
};