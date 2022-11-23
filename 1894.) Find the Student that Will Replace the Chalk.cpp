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

// Approach-2

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        vector<long long> v;
        for(int i=0;i<chalk.size();i++)
        {
            sum += chalk[i];
            v.push_back(sum);
        }
        k %= sum;
        int l = 0, h = v.size()-1, mid;
        while(l<h)
        {
            mid = (l+h)/2;
            if(k==v[mid])
                return mid+1;
            else if(k<v[mid])
                h = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};