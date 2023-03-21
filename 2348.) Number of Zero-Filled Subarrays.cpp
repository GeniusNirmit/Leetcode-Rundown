class Solution {
public:
    long long zeroFilledSubarray(vector<int>& a) {
        long long counter = 0;
        long long current = 0;
        for(int i=0;i<a.size();i++)
        {
            current++;
            if(a[i] != 0)
                current = 0;
            counter += current;
        }
        return counter;
    }
};