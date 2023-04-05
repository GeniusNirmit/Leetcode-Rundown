// Approach - 1

class Solution {
public:
    int minimizeArrayValue(vector<int>& a) {
        long long sum = 0, minMaxNum = 0;
        for(int i=0; i<a.size(); i++)
        {
            sum += a[i];
            minMaxNum = max(minMaxNum, (sum + i) / (i + 1));
        }
        return minMaxNum;
    }
};

// Approach - 2

class Solution {
public:
    bool isMinimum(int mid, vector<int> a) {
        long long sum = 0;
        for(int i=0; i<a.size(); i++)
        {
            sum += a[i];
            if(sum > (long long)mid * (i + 1))
                return false;
        }
        return true;
    }
    int minimizeArrayValue(vector<int>& a) {
        int l = *min_element(a.begin(), a.end()), h = *max_element(a.begin(), a.end()), mid;

        while(l < h)
        {
            mid = (l + h)/2;
            if(isMinimum(mid, a))
                h = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};