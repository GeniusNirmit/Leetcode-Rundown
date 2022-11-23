// Approach-1

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for(int i=0;i<chalk.size();i++)
            sum += chalk[i];
        k %= sum;
        if(k!=0)
        {
            for(int i=0;i<chalk.size();i++)
            {
                k -= chalk[i];
                if(k < 0)
                    return i;
            }
        }
        return 0;
    }
};