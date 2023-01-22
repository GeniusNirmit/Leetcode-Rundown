class Solution {
public:
    int alternateDigitSum(int n) {
        long long sum = 0;
        int counter = 0;
        int val = n;
        vector<int> digits;
        while(val > 0)
        {
            digits.push_back(val % 10);
            val /= 10;
        }
        for(int i=digits.size()-1;i>=0;i--)
        {
            if(counter % 2 == 0)
                sum += digits[i];
            else
                sum -= digits[i];
            counter++;
        }
        return sum;
    }
};