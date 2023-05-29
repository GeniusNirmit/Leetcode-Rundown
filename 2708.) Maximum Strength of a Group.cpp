class Solution {
public:
    long long maxStrength(vector<int>& a) {
        int counter = 0, maxNegNum = -10, maxNum = -1;
        long long maximumStrength = 1;

        for(int i=0; i<a.size(); i++)
        {
            if(a[i] != 0)
                maximumStrength *= a[i];
            if(a[i] < 0)
            {
                counter++;
                maxNegNum = max(maxNegNum, a[i]);
            }
            maxNum = max(maxNum, a[i]);
        }
        if(maxNum == 0 && counter < 2)
            return 0;
        if(counter == 1 && a.size() == 1)
            return a[0];
        if(counter % 2 != 0)
            maximumStrength /= maxNegNum;
        return maximumStrength;
    }
};