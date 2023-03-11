class Solution {
public:
    int calculate(string s) {
        int answer = 0, sign = 1;
        stack<int> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                int num = 0;
                while(i < s.length() && s[i] >= '0' && s[i] <= '9')
                {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                answer += sign * num;
                i--;
            }
            else if(s[i] == '+')
                sign = 1;
            else if(s[i] == '-')
                sign = -1;
            else if(s[i] == '(')
            {
                st.push(answer);
                st.push(sign);
                answer = 0;
                sign = 1;
            }
            else if(s[i] == ')')
            {
                answer *= st.top();
                st.pop();
                answer += st.top();
                st.pop();
            }
        }
        return answer;
    }
};