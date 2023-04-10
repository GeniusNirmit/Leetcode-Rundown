class Solution {
public:
    long long makeSubKSumEqual(vector<int>& a, int k) {
        int n = a.size();
        k = __gcd(k, n);
        long long counter = 0;

        for(int i=0; i<k; i++)
        {
            vector<int> v;
            for(int j=i; j<a.size(); j+=k)
                v.push_back(a[j]);

            sort(v.begin(), v.end());

            long long mid = v[v.size()/2];

            for(int j=i; j<a.size(); j+=k)
                counter += abs(mid - a[j]);
        }

        return counter;
    }
};