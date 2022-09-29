class Solution {
public:
    bool isValid(string x) {
        stack<char> s;
        for(int i=0;i<x.length();i++)
        {
            if(x[i]=='(')
                s.push(')');
            else if(x[i]=='[')
                s.push(']');
            else if(x[i]=='{')
                s.push('}');
            else if(x[i]==')' || x[i]=='}' || x[i]==']')
            {
                if(s.empty() || s.top()!=x[i])
                    return false;
                else if(x[i]==s.top())
                    s.pop();
            }
        }
        if(s.empty())
            return true;
        return false;
    }
};