class Solution {
public:
    int convertToInteger(string token) {
        int tokenInteger = 0;
        bool isNegative = false;
        int i = 0;
        if(token[i]=='-')
        {
            isNegative = true;
            i++;
        }
        while(i<token.length())
        {
            tokenInteger = tokenInteger * 10 + (token[i]-'0');
            i++;
        }
        if(isNegative)
            tokenInteger = -tokenInteger;
        return tokenInteger;
    }
    int evalRPN(vector<string>& tokens) {
        stack<long long> tokenStack;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/")
                tokenStack.push(convertToInteger(tokens[i]));
            else
            {
                long long operand2 = tokenStack.top();
                tokenStack.pop();
                long long operand1 = tokenStack.top();
                tokenStack.pop();
                long long result;
                if(tokens[i]=="+")
                    result = operand1 + operand2;
                else if(tokens[i]=="-")
                    result = operand1 - operand2;
                else if(tokens[i]=="*")
                    result = operand1 * operand2;
                else
                    result = operand1 / operand2;
                tokenStack.push(result);
            }
        }
        return tokenStack.top();
    }
};