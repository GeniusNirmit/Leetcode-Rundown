class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stringIndex;
        stringIndex.push(0);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                stringIndex.push(0);
            else
            {
                int temp1 = stringIndex.top();
                stringIndex.pop();
                int temp2 = stringIndex.top();
                stringIndex.pop();
                temp2 += max(2*temp1,1);
                stringIndex.push(temp2);
            }
        }
        return stringIndex.top();
    }
};