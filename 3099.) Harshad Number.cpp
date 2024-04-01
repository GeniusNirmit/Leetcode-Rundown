class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        string num = to_string(x);
        int sum = 0;
        
        for(int i = 0; i < num.length(); i++)
            sum += num[i] - '0';
    
        if(x % sum == 0)
            return sum;
        return -1;
    }
};