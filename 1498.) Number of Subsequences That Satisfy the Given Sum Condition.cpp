class Solution {
public:
    int numSubseq(vector<int>& a, int target) {
        sort(a.begin(), a.end());

        long long MOD = 1e9 + 7;
        int counter = 0;
        int i = 0, j = a.size() - 1;
        vector<int> powerOfTwo;
        powerOfTwo.push_back(1);
        cout << MOD ;
        for(int i=1; i<a.size(); i++)
            powerOfTwo.push_back((powerOfTwo[i-1]*2) % MOD);

        while(i <= j)
        {
            if(a[i] + a[j] <= target)
            {
                counter += powerOfTwo[j - i];
                counter %= MOD;
                i++;
            }
            else
                j--;
        }
        return counter;
    }
};