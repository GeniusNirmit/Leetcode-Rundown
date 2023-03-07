class Solution {
public:
    int splitNum(int n) {
        string num1, num2, num = to_string(n);
        sort(num.begin(), num.end());
        for(int i=0;i<num.length();i+=2)
            num1 += num[i];
        for(int i=1;i<num.length();i+=2)
            num2 += num[i];
        return stoi(num1) + stoi(num2);
    }
};