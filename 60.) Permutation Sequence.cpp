class Solution {
public:
    string getPermutation(int n, int k) {
        long long nFactorial = 1;
        string number;
        string kPermutation;
        for(int i=1; i<n; i++)
        {
            nFactorial *= i;
            number += '0' + i;
        }
        number += '0' + n;
        k -= 1;

        while(true)
        {
            kPermutation.push_back(number[k/nFactorial]);
            number.erase(number.begin() + k/nFactorial);
            if(!number.length())
                break;
            k %= nFactorial;
            nFactorial /= number.length();
        }
        return kPermutation;
    }
};