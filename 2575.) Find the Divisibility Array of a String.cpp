class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> divisible(word.length());
        long long num = (word[0] - '0') % m;
        for(int i=0;i<word.length()-1;i++)
        {
            if(num % m == 0)
                divisible[i] = 1;
            num *= 10;
            num += word[i+1] - '0';
            num %= m;
        }
        if(num % m == 0)
            divisible[word.length()-1] = 1;
        return divisible;
    }
};