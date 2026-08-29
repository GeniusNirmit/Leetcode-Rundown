class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        vector<long long> intervalsSum(n);

        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        for(auto [num, indices]: mp) {
            long long leftSum = 0;
            long long rightSum = 0;
            long long numIndex = indices.size();

            for(long long i = 0; i < numIndex; i++) {
                rightSum += indices[i];
            }
            
            for(long long i = 0; i < numIndex; i++) {
                rightSum -= indices[i];

                long long leftDist = (i * indices[i]) - leftSum;
                long long rightDist = rightSum - ((numIndex - i - 1) * indices[i]);

                intervalsSum[indices[i]] = leftDist + rightDist;

                leftSum += indices[i];
            }
        }

        return intervalsSum;
    }
};